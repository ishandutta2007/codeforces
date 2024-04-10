#include <iostream>
#include <cstdio>
#include <algorithm>

#define lint long long int
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

        inline InputReader &operator >>(lint &n) {
            while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
                advance();
            }

            int semn = 1;
            if (buffer[cursor] == '-') {
                semn = -1;
                advance();
            }

            n = 0;

            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }

            n *= semn;
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

const int NMAX = 100005;
const lint INF = 3000000000000000000LL;

int n;
struct Point {
    lint x, y, z;

    lint xyz;
    lint xy_z;
    lint x_yz;
    lint x_y_z;
} points[NMAX];

lint round_up(lint x) {
    if (x % 2 == 0)
        return x / 2;
    else if (x > 0)
        return x / 2 + 1;
    else
        return x / 2;
}

lint round_down(lint x) {
    if (x % 2 == 0)
        return x / 2;
    else if (x > 0)
        return x / 2;
    else
        return x / 2 - 1;
}

bool works(lint bound, bool print = false) {
    lint l1 = -INF;
    lint u1 =  INF;
    lint l2 = -INF;
    lint u2 =  INF;
    lint l3 = -INF;
    lint u3 =  INF;
    lint l4 = -INF;
    lint u4 =  INF;

    for (int i = 1; i <= n; ++ i) {
        l1 = max(l1, points[i].xyz   - bound);
        u1 = min(u1, points[i].xyz   + bound);

        l2 = max(l2, points[i].xy_z  - bound);
        u2 = min(u2, points[i].xy_z  + bound);

        l3 = max(l3, points[i].x_yz  - bound);
        u3 = min(u3, points[i].x_yz  + bound);

        l4 = max(l4, points[i].x_y_z - bound);
        u4 = min(u4, points[i].x_y_z + bound);
    }

    if (l1 > u1)
        return false;
    if (l2 > u2)
        return false;
    if (l3 > u3)
        return false;
    if (l4 > u4)
        return false;

    for (int r = 0; r < 2; ++ r) {
        lint n_l1 = round_up(l1 - r);
        lint n_u1 = round_down(u1 - r);
        lint n_l2 = round_up(l2 - r);
        lint n_u2 = round_down(u2 - r);
        lint n_l3 = round_up(l3 - r);
        lint n_u3 = round_down(u3 - r);
        lint n_l4 = round_up(l4 - r);
        lint n_u4 = round_down(u4 - r);

        if (n_l1 > n_u1)
            continue;
        if (n_l2 > n_u2)
            continue;
        if (n_l3 > n_u3)
            continue;
        if (n_l4 > n_u4)
            continue;

        lint L = max(n_l4, n_l2 + n_l3 - n_u1);
        lint U = min(n_u4, n_u2 + n_u3 - n_l1);

        if (L <= U) {
            if (print) {
                lint b1 = n_u1;
                lint b2 = n_l2;
                lint b3 = n_l3;

                //Marim b2
                if (b2 + b3 - b1 + (n_u2 - n_l2) < L)
                    b2 = n_u2;
                else
                    b2 += (L - (b2 + b3 - b1));

                //Marim b3
                if (b2 + b3 - b1 + (n_u3 - n_l3) < L)
                    b3 = n_u3;
                else
                    b3 += (L - (b2 + b3 - b1));

                //Micsoram b1
                if (b2 + b3 - b1 + (n_u1 - n_l1) < L)
                    b1 = n_l1;
                else
                    b1 -= (L - (b2 + b3 - b1));

                lint x = b2 + b3 + r;
                lint y = b1 - b3;
                lint z = b1 - b2;

                cout << x << ' ' << y << ' ' << z << '\n';
            }

            return true;
        }
    }

    return false;
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    int t = 0;
    cin >> t;

    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) {
            cin >> points[i].x >> points[i].y >> points[i].z;

            points[i].xyz   = points[i].x + points[i].y + points[i].z;
            points[i].xy_z  = points[i].x + points[i].y - points[i].z;
            points[i].x_yz  = points[i].x - points[i].y + points[i].z;
            points[i].x_y_z = points[i].x - points[i].y - points[i].z;
        }

        lint st = 0;
        lint dr = INF;
        lint ans = dr + 1;
        lint mid;

        while (st <= dr) {
            mid = (st + dr) >> 1;
            if (works(mid)) {
                ans = mid;
                dr = mid - 1;
            }
            else
                st = mid + 1;
        }

        works(ans, true);
    }

    return 0;
}