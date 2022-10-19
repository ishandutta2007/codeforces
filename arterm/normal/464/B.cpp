#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define long long long
#define N 8

int order[6][3] =
{{0, 1, 2},
 {0, 2, 1},
 {1, 0, 2},
 {1, 2, 0},
 {2, 0, 1},
 {2, 1, 0}};

struct point {
    long a[3];
    void read() {
        for (int i = 0; i < 3; ++i)
            cin >> a[i];
    }
    long len() {
        long ans = 0;
        for (int i = 0; i < 3; ++i)
            ans = ans + a[i] * a[i];
        return ans;
    }
    point operator - (const point &x) const {
        point ans;
        for (int i = 0; i < 3; ++i)
            ans.a[i] = a[i] - x.a[i];
        return ans;
    }
    point operator + (const point &x) const {
         point ans;
        for (int i = 0; i < 3; ++i)
            ans.a[i] = a[i] + x.a[i];
        return ans;
    }
    long operator * (const point &x) const {
        long ans = 0;
        for (int i = 0; i < 3; ++i)
            ans = ans + a[i] * x.a[i];
        return ans;
    }
    bool operator ==(const point &x) const {
        bool ans = true;
        for (int i = 0; i < 3; ++i)
            ans &= x.a[i] == a[i];
        return ans;
    }
    bool operator < (const point &x) const {
        for (int i = 0; i < 3; ++i) {
            if (a[i] < x.a[i])
                return true;
            if (a[i] > x.a[i])
                return false;
        }
        return false;
    }
} p[N], b[N];

point apply(const point &p, int * order) {
    point ans;
    for (int i = 0; i < 3; ++i)
        ans.a[i] = p.a[order[i]];
    return ans;
}

void apply(int x) {
    b[0] = p[0];
    for (int i = 1; i <= 7; ++i) {
        b[i] = apply(p[i], order[x % 6]);
        x /= 6;
    }
}

long d[N];
long con[] = {0, 1, 1, 1, 2, 2, 2, 3};
point cube[8];

bool isCube() {
    for (int i = 7; i >= 0; --i)
        b[i] = b[i] - b[0];

    for (int i = 0; i < 8; ++i)
        d[i] = b[i].len();

    sort(d, d + 8);
    long t = d[1];
    if (t == 0)
        return false;
    for (int i = 0; i < 8; ++i)
        if (d[i] != con[i] * t)
            return false;

    int k = 1;
    for (int i = 1; i < 8; ++i)
        if (b[i].len() == t) {
            swap(b[i], b[k]);
            ++k;
        }

    for (int i = 1; i <= 3; ++i)
        for (int j = i + 1; j <= 3; ++j)
            if (b[i] * b[j] != 0) {
                return false;
            }

    //point cube[] = {b[0], b[1], b[2], b[3], b[1] + b[2], b[1] + b[3], b[2] + b[3], (b[1] + b[2]) + b[3]};
    cube[0] = b[0];
    cube[1] = b[1];
    cube[2] = b[2];
    cube[3] = b[3];
    cube[4] = b[1] + b[2];
    cube[5] = b[1] + b[3];
    cube[6] = b[2] + b[3];
    cube[7] = (b[1] + b[2]) + b[3];


    sort(b, b + 8);
    sort(cube, cube + 8);

    for (int i = 0; i < 8; ++i)
        if (!(b[i] == cube[i]))
            return false;
    return true;

}

void kill() {
    for (int i = 0; i < 8; ++i)
        p[i].read();

    int c = 1;
    for (int i = 0; i < 7; ++i)
        c *= 6;
    for (int i = 0; i < c; ++i) {
        apply(i);
        if (isCube()) {
            apply(i);
            cout << "YES\n";
            for (int i = 0; i < 8; ++i, cout << "\n")
                for (int j = 0; j < 3; ++j, cout << " ")
                    cout << b[i].a[j];
            return;
        }
    }
    cout << "NO\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    kill();
    return 0;
}