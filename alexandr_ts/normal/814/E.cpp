#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 1e6 + 10;
const int N = 51; /// CHANGE!!!
const int POW = 20;
const ll MOD = 1000 * 1000 * 1000 + 7;

int a[N];
int d[2][N][N][N][N];

void add(int &a, ll add) {
    a = ((ll)a + add) % MOD;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];

    if (a[0] == 3) {
        if (a[1] == 2)
            d[1][0][1][1][0] = 1;
        else
            d[1][0][1][0][1] = 1;
    }
    else {
        d[0][0][0][0][1] = 1;
    }


    frab(i, a[0] - 2, n - 1) {
        fr(s1, n + 1)
            fr(s2, n + 1)
                fr(t1, n + 1)
                    fr(t2, n + 1)
                        d[(i + 1) % 2][s1][s2][t1][t2] = 0;
        fr(s1, n + 1)
            fr(s2, n + 1)
                fr(t1, n + 1)
                    fr(t2, n + 1) {
                        if (d[i % 2][s1][s2][t1][t2] == 0) continue;
                        assert(s1 < n && s2 < n && t1 < n && t2 < n);
                        //cout << i << " " << s1 << " " << s2 << " " << t1 << " " << t2 << " " << d[i % 2][s1][s2][t1][t2] << endl;
                        ll cur = d[i % 2][s1][s2][t1][t2];
                        if (s1 + s2 == 0) {
                            if (t1)
                                add(d[(i+1)%2][t1 - 1][t2][a[i + 1] == 2][a[i + 1] == 3], cur * t1);
                            if (t2)
                                add(d[(i+1)%2][t1 + 1][t2 - 1][a[i + 1] == 2][a[i + 1] == 3], cur * t2);
                        }
                        if (s1) {
                            add(d[(i+1)%2][s1 - 1][s2][t1 + (a[i + 1] == 2)][t2 + (a[i + 1] == 3)], cur * s1);
                            if (a[i + 1] == 2) {
                                if (t1)
                                    add(d[(i+1)%2][s1 - 1][s2][t1 - 1][t2], cur * s1 * t1);
                                if (t2)
                                    add(d[(i+1)%2][s1 - 1][s2][t1 + 1][t2 - 1], cur * s1 * t2);
                            }
                            else if (a[i + 1] == 3) {
                                if (t1)
                                    add(d[(i+1)%2][s1 - 1][s2][t1][t2], cur * s1 * t1);
                                if (t1 >= 2)
                                    add(d[(i+1)%2][s1 - 1][s2][t1 - 2][t2], cur * s1 * (t1 * (t1 - 1) / 2));
                                if (t2 >= 2)
                                    add(d[(i+1)%2][s1 - 1][s2][t1 + 2][t2 - 2], cur * s1 * (t2 * (t2 - 1) / 2));
                                if (t2)
                                    add(d[(i+1)%2][s1 - 1][s2][t1 + 2][t2 - 1], cur * s1 * t2);
                                if (t1 && t2)
                                    add(d[(i+1)%2][s1 - 1][s2][t1][t2 - 1], cur * s1 * t1 * t2);
                            }
                        }
                        if (s2) {
                            //cout << "!" << endl;
                            add(d[(i+1)%2][s1 + 1][s2 - 1][t1 + (int)(a[i + 1] == 2)][t2 + (int)(a[i + 1] == 3)], cur * s2);
                            if (a[i + 1] == 2) {
                                //cout << "!@" << endl;
                                if (t1)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1 - 1][t2], cur * s2 * t1);
                                if (t2)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1 + 1][t2 - 1], cur * s2 * t2);
                            }
                            else if (a[i + 1] == 3) {
                                //cout << "** " << i << " " << t1 << " " << t2 << " " << s2 << " " << cur << endl;
                                if (t1)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1][t2], cur * s2 * t1); ///ok
                                if (t1 >= 2)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1 - 2][t2], cur * s2 * (t1 * (t1 - 1) / 2)); ///ok;
                                if (t2 >= 2)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1 + 2][t2 - 2], cur * s2 * (t2 * (t2 - 1) / 2));
                                if (t2)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1 + 2][t2 - 1], cur * s2 * t2); ///ok
                                if (t1 && t2)
                                    add(d[(i+1)%2][s1 + 1][s2 - 1][t1][t2 - 1], cur * s2 * t1 * t2); /// ok
                            }
                        }
                    }
    }

//    int ans = 0;
//    fr(s1, n + 1)
//        fr(s2, n + 1)
//            fr(t1, n + 1)
//                fr(t2, n + 1)
//                    add(ans, d[n - 1][s1][s2][t1][t2]);
//    cout << ans;
    cout << d[(n + 1) % 2][0][0][0][0];
    return 0;
}