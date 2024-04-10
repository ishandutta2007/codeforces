#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

const int INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int M = 1e3 + 10;
const int N = 1e3 + 10;

ll x[N], y[N];

int a[N][N];//, b[N];

//int pts(int mn, int pt) {
//    return pt - mn * pt / 250;
//}

int p[N];

bool check(int t) {
    fr(i, 5) {
        if (a[0][i] != -1) {
            if (p[i] != 5 && (x[i] + t) * (1 << (p[i] + 1)) <= (y[i] + t)) return false;
            if (((y[i] + t) < x[i] * (1 << p[i]))) return false;
        }
        else {
            if (p[i] != 5 && (x[i]) * (1 << (p[i] + 1)) <= (y[i] + t)) return false;
            if (((y[i] + t) < x[i] * (1 << p[i]))) return false;
        }
    }
    return true;
}

bool er = false;

bool check2() {
    int v1 = 0, v2 = 0;
    fr(i, 5) {
        int mx = 500 + p[i] * 500;
        if (a[0][i] != -1)
            v1 += mx - a[0][i] * mx / 250;
        if (a[1][i] != -1)
            v2 += mx - a[1][i] * mx / 250;
    }
    return v1 > v2;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        fr(j, 5) {
            cin >> a[i][j];
            if (a[i][j] == -1)
                y[j]++;
            else
                x[j]++, y[j]++;
        }


    //int ans = INF;

    //ll l = -1, r = INF + 1;

    for (int tm = 0; tm < 3842; tm++) {
        //int tm = (r + l) / 2;
        bool fnd = false;
        fr(i1, 6)
        fr(i2, 6)
        fr(i3, 6)
        fr(i4, 6)
        fr(i5, 6) {
//            vector <int> p;
//            p.pb(i1), p.pb(i2), p.pb(i3), p.pb(i4), p.pb(i5);
            p[0] = i1;
            p[1] = i2;
            p[2] = i3;
            p[3] = i4;
            p[4] = i5;

            if (check2()) {
                //for (auto tmp: p) cout << tmp << " ";cout << endl;
                //cout << "!" << endl;
                if (check(tm)) {
                    //cout << "!" << endl;
                    fnd = true;
                }
            }
        }
        if (fnd) {
            cout << tm;
            return 0;
        }
    }
    cout << -1;
}