#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1005;
const int mod = 1000000007;

void add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int dp[maxn][2 * maxn][2];


vector<int> decr(vector<int> a) {
    a.back()--;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] < 0) {
            a[i - 1]--;
            a[i] += 10;
        } else {
            break;
        }
    }
    return a;
}

bool lucky(int n, int k) {
    vector<int> pos;
    int p = 0;
    while (n) {
        if (n % 10 == 4 || n % 10 == 7) {
            pos.pb(p);
        }
        n /= 10;
        p++;
    }
    for (int i = 0; i + 1 < pos.size(); i++) {
        if (pos[i + 1] - pos[i] <= k) {
            return true;
        }
    }

    return false;
}


int brute(int l, int r, int k) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += lucky(i, k);
    }
    return ans;
}

char sl[maxn], sr[maxn];

void gen() {
    ofstream out("a.in");
    int t = 1000, k = 5;
    out << t << " " << k << endl;
    for (int j = 0; j < t; j++) {
        out << "1 ";
        for (int i = 0; i < 1000; i++) {
            out << "9";
        }
        out << endl;
    }
    out.close();
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int t, k;
    cin >> t >> k;

    dp[0][maxn - 1][0] = 1;

    for (int len = 0; len + 1 < maxn; len++) {
        for (int dist = 0; dist < 2 * maxn; dist++) {
            for (int was = 0; was < 2; was++) {
                for (int d = 0; d < 10; d++) {
                    if (d == 4 || d == 7) {
                        add(dp[len + 1][0][was || (dist + 1 <= k)], dp[len][dist][was]);
                    } else {
                        if (dist + 1 < 2 * maxn) {
                            add(dp[len + 1][dist + 1][was], dp[len][dist][was]);
                        }
                    }
                }
            }
        }
    }

    for (int len = 0; len < maxn; len++) {
        for (int dist = 0; dist + 1 < maxn * 2; dist++) {
            for (int was = 0; was < 2; was++) {
                add(dp[len][dist + 1][was], dp[len][dist][was]);
            }
        }
    }

    auto solve = [&](vector<int> a) {
        int ans = 0;
        int dist = maxn - 1;
        int was = 0;

        for (int i = 0; i < a.size(); i++) {
            for (int d = 0; d < a[i]; d++) {
                if (d == 4 || d == 7) {
                    int newDist = 0;
                    int newWas = was || (dist + 1) <= k;

                    if (newWas) {
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][0]);
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][1]);
                    } else {
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][1]);
                        add(ans, dp[a.size() - i - 1][k - 1 - newDist][0]);
                    }
                } else {
                    int newDist = dist + 1;
                    int newWas = was;

                    if (newWas) {
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][0]);
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][1]);
                    } else {
                        add(ans, dp[a.size() - i - 1][maxn * 2 - 1][1]);
                        if (k - 1 - newDist >= 0) {
                            add(ans, dp[a.size() - i - 1][k - 1 - newDist][0]);
                        }
                    }
                }
            }

            if (a[i] == 4 || a[i] == 7) {
                int newDist = 0;
                int newWas = was || (dist + 1 <= k);

                dist = newDist;
                was = newWas;
            } else {
                dist = dist + 1;
            }


            if (0&&i) {
                for (int d = 1; d < 10; d++) {
                    if (d == 4 || d == 7) {
                        add(ans, dp[a.size() - 1 - i][k - 1][0]);
                        add(ans, dp[a.size() - 1 - i][maxn * 2 - 1][1]);
                    } else {
                        add(ans, dp[a.size() - 1 - 1][maxn * 2 - 1][1]);
                    }
                }
            }
        }

        if (was) {
            add(ans, dp[0][maxn * 2 - 1][0]);
            add(ans, dp[0][maxn * 2 - 1][1]);
        } else {
            add(ans, dp[0][maxn * 2 - 1][1]);
        }

        return ans;
    };


    while (t--) {
        scanf("%s %s\n", sl, sr);
        int nl = strlen(sl);
        int nr = strlen(sr);


        int lx = 0, rx =0;

        vector<int> l;
        for (int i = 0; i < nl; i++) {
            l.pb(sl[i] - '0');
            lx = lx * 10 + l.back();
        }

        vector<int> r;
        for (int i = 0; i < nr; i++) {
            r.pb(sr[i] - '0');
            rx = rx * 10 + r.back();
        }

        int ans = solve(r);
        sub(ans, solve(decr(l)));

       // cerr << lx << " " << rx << endl;


        cout << ans << endl;
       // cout << brute(lx, rx, k) << endl;
    }

    return 0;
}