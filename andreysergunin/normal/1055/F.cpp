#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 1000100;

int cnt[2];
int len[2][2 * MAXN];
ll a[2][2 * MAXN];
ll p1[MAXN], p2[MAXN], q1[MAXN], q2[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    ll k;
    cin >> n >> k;
    // n = 1000000; k = rnd() % ((ll)n * n) + 1;

    for (int i = 1; i < n; ++i) {
        int u, v;
        ll w;
        cin >> v >> w;
        --v;
        // v = 0; w = ((ll)i << 40);
        a[0][i] = a[0][v] ^ w;
        a[0][i + n] = a[0][i];
    }
    cnt[0] = 2;
    len[0][0] = len[0][1] = n;

    ll res = 0;
    int t = 0;

    for (int d = 61; d >= 0; --d) {
        ll cnt0 = 0;

        int cur = 0;

        for (int i = 0; i < cnt[t]; i += 2) {
            ll u1 = 0, v1 = 0;
            for (int j = 0; j < len[t][i]; ++j, ++cur) {
                ll x = a[t][cur];
                if (x & (1ll << d)) {
                    ++u1;
                } else {
                    ++v1;
                }
            }
            
            ll u2 = 0, v2 = 0;
            for (int j = 0; j < len[t][i + 1]; ++j, ++cur) {
                ll x = a[t][cur];
                if (x & (1ll << d)) {
                    ++u2;
                } else {
                    ++v2;
                }
            }

            cnt0 += u1 * u2 + v1 * v2;
        }

        cur = 0;

        int cur1 = 0;
        cnt[t ^ 1] = 0;

        if (k <= cnt0) {
            for (int i = 0; i < cnt[t]; i += 2) {
                int sp1 = 0, sq1 = 0;
                for (int j = 0; j < len[t][i]; ++j, ++cur) {
                    ll x = a[t][cur];
                    if (x & (1ll << d)) {
                        p1[sp1++] = x;
                    } else {
                        q1[sq1++] = x;
                    }
                }

                int sp2 = 0, sq2 = 0;
                for (int j = 0; j < len[t][i + 1]; ++j, ++cur) {
                    ll x = a[t][cur];
                    if (x & (1ll << d)) {
                        p2[sp2++] = x;
                    } else {
                        q2[sq2++] = x;
                    }
                }
                
                if (sp1 > 0 && sp2 > 0) {
                    for (int j = 0; j < sp1; ++j, ++cur1) {
                        a[t ^ 1][cur1] = p1[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sp1;

                    for (int j = 0; j < sp2; ++j, ++cur1) {
                        a[t ^ 1][cur1] = p2[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sp2;
                }


                if (sq1 > 0 && sq2 > 0) {
                    for (int j = 0; j < sq1; ++j, ++cur1) {
                        a[t ^ 1][cur1] = q1[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sq1;

                    for (int j = 0; j < sq2; ++j, ++cur1) {
                        a[t ^ 1][cur1] = q2[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sq2;
                }
            }
        } else {
            k -= cnt0;
            res ^= (1ll << d);
            
            for (int i = 0; i < cnt[t]; i += 2) {
                int sp1 = 0, sq1 = 0;
                for (int j = 0; j < len[t][i]; ++j, ++cur) {
                    ll x = a[t][cur];
                    if (x & (1ll << d)) {
                        p1[sp1++] = x;
                    } else {
                        q1[sq1++] = x;
                    }
                }

                int sp2 = 0, sq2 = 0;
                for (int j = 0; j < len[t][i + 1]; ++j, ++cur) {
                    ll x = a[t][cur];
                    if (x & (1ll << d)) {
                        p2[sp2++] = x;
                    } else {
                        q2[sq2++] = x;
                    }
                }
                
                if (sp1 > 0 && sq2 > 0) {
                    for (int j = 0; j < sp1; ++j, ++cur1) {
                        a[t ^ 1][cur1] = p1[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sp1;

                    for (int j = 0; j < sq2; ++j, ++cur1) {
                        a[t ^ 1][cur1] = q2[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sq2;
                }


                if (sq1 > 0 && sp2 > 0) {
                    for (int j = 0; j < sq1; ++j, ++cur1) {
                        a[t ^ 1][cur1] = q1[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sq1;

                    for (int j = 0; j < sp2; ++j, ++cur1) {
                        a[t ^ 1][cur1] = p2[j];
                    }   
                    len[t ^ 1][cnt[t ^ 1]++] = sp2;
                }
            }
        }
        t ^= 1;
    }

    cout << res << endl;
}