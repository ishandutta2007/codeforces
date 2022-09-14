#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

ll get(int a, int b, int c, int zeros, int ones, int ends, vector<int> l) {
    // cerr << a << " " << b << " " << c << " " << zeros << " " << ones << " " << ends << endl;;
    // for (int x : l) {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    vector<int> cl = l;
    int czeros = zeros;

    ll pot_ones = 0;
    while (!cl.empty() && cl.back() == 1) {
        cl.pop_back();
        ++pot_ones;
    } 

    ll best = 0;
    ll cur = 0;

    for (int turn = 0; ; turn ^= 1) {
        if (turn == 0) {    
            if (!cl.empty()) {
                --cl.back();
                cur += a;
                if (!cl.empty() && cl.back() == 1) {
                    cl.pop_back();
                    ++pot_ones;
                }   
            } else if (czeros > 0) {
                --czeros;
                cur += a;
            } else if (pot_ones > 0) {
                --pot_ones;
                cur -= c;
                ++ones;
            } else if (ends > 0) {
                --ends;
                cur -= c;
            } else {
                break;
            }
        } else {
            if (ones > 0) {
                --ones;
                cur += b;
            } else if (pot_ones > 0) {  
                

                if (czeros == zeros) {  

                    bool quit = false;
                    while (true) {
                        int k = sz(cl) - 1;
                        if (k == -1 || cl[k] == l[k]) {
                            if (sz(l) == k + 1 || l[k + 1] == 1) {
                                quit = true;
                                break;
                            } else {
                                cl.push_back(1);
                                --pot_ones;
                                if (pot_ones == 0) {
                                    quit = true;
                                    break;
                                }
                            }
                        } else {
                            ++cl[k];
                            break;
                        }
                    }

                    if (quit) {
                        break;
                    }
                } else {
                    ++czeros;
                }
                
                --pot_ones;
                cur -= a + c;
                cur += b;
            } else {
                break;
            }
        }
        best = max(best, cur);
        // cerr << "---> " << turn << " " << cur << " " << best << " " << pot_ones << " " << ones << endl;
    }
    return best;
}

void solve() {
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;

    ll zeros = 0, ones = 0;
    for (int i = 0; i < n - 1; ++i) {
        ones += s[i] == '1' && s[i + 1] == '1';
    }
    vector<int> l;
    int len = 0;
    int ends = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++len;
        } else if (len > 0) {
            if (len != i) {
                l.push_back(len);
            } else {
                zeros += len - 1;
                ++ends;
            }
            len = 0;
        }
    }
    if (len) {
        zeros += len - 1;
        ++ends;
    }

    sort(all(l), greater<int>());
    ll res = get(a, b, c, zeros, ones, ends, l);
    if (ones > 0) {
        res = max(res, b + get(a, b, c, zeros, ones - 1, ends, l));
    }
    // cerr << "answer: ";
    cout << res << endl;
}