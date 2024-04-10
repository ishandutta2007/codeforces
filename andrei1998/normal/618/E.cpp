#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

class InputReader {
    public:
        InputReader() {
            cursor = 0;
            fread(buffer, SIZE, 1, stdin);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, stdin);
            }
        }
};

const double PI = acos(-1);
double sins[360];
double coss[360];

struct point {
    double x, y;

    point(double _x = 0, double _y = 0): x(_x), y(_y) {}

    inline double norm() {
        return sqrt(x * x + y * y);
    }

    inline point operator+(const point &b) const {
        return point(x + b.x, y + b.y);
    }

    inline void add_angle(int alpha) {
        double new_x =  x * coss[alpha] + y * sins[alpha];
        double new_y = -x * sins[alpha] + y * coss[alpha];

        x = new_x;
        y = new_y;
    }
};

const int NMAX = 300005;

struct node {
    int st, dr;
    point sum; //Position vector of the interval

    int lazy_ang;

    void make_lazy(int alpha) {
        sum.add_angle(alpha);
        lazy_ang += alpha;

        if (lazy_ang >= 360)
            lazy_ang -= 360;
    }
} arb[4 * NMAX];

void propagate(int pos) {
    if (arb[pos].lazy_ang) {
        arb[pos << 1].make_lazy(arb[pos].lazy_ang);
        arb[(pos << 1) + 1].make_lazy(arb[pos].lazy_ang);

        arb[pos].lazy_ang = 0;
    }
}

void build(int st, int dr, int pos) {
    arb[pos].st = st, arb[pos].dr = dr;
    arb[pos].sum = point(dr - st + 1, 0);

    if (st == dr)
        return ;

    int mijl = (st + dr) >> 1;
    build(st, mijl, pos << 1);
    build(mijl + 1, dr, (pos << 1) + 1);
}

void update_tr(int where, int l, int pos) {
    if (arb[pos].st == arb[pos].dr) {
        double d = arb[pos].sum.norm();
        arb[pos].sum = point(arb[pos].sum.x + l * (arb[pos].sum.x / d), arb[pos].sum.y + l * (arb[pos].sum.y / d));

        return ;
    }

    propagate(pos);

    int mijl = (arb[pos].st + arb[pos].dr) >> 1;
    if (where <= mijl)
        update_tr(where, l, pos << 1);
    else
        update_tr(where, l, (pos << 1) + 1);
    arb[pos].sum = arb[pos << 1].sum + arb[(pos << 1) + 1].sum;
}

void update_ang(int where, int alpha, int pos) {
    if (arb[pos].st == where) {
        arb[pos].make_lazy(alpha);
        return ;
    }

    propagate(pos);

    int mijl = (arb[pos].st + arb[pos].dr) >> 1;
    if (where <= mijl) {
        update_ang(where, alpha, pos << 1);
        update_ang(mijl + 1, alpha, (pos << 1) + 1);
    }
    else
        update_ang(where, alpha, (pos << 1) + 1);
    arb[pos].sum = arb[pos << 1].sum + arb[(pos << 1) + 1].sum;
}

int main()
{
    InputReader cin;

    for (int i = 0; i < 360; ++ i) {
        sins[i] = sin(i * PI / 180);
        coss[i] = cos(i * PI / 180);
    }

    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    build(1, n, 1);

    cout << fixed << setprecision(10);

    int type, where, val;
    while (m --) {
        cin >> type >> where >> val;

        if (type == 1)
            update_tr(where, val, 1);
        else
            update_ang(where, val, 1);

        cout << arb[1].sum.x << ' ' << arb[1].sum.y << '\n';
    }

    return 0;
}