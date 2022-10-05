#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("Ofast")
using namespace std;
// debug template
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
//
inline void yes() {
	cout << "YES" << endl;
	return;
}
inline void no() {
	cout << "NO" << endl;
	return;
}
template <class T>
inline void out(T temp) {
	cout << temp << endl;
	return;
}
// global
#define int long long
const int MOD = 1e9 + 7;
// {x-2, x-1, x}
vector<vector<int> > transf = {
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 1}
};
// {x-2, x-1, x, n, 1}
vector<vector<int> > transc = {
    {0, 0, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1000000002,1, 1}
};
// multiply
int temp[5][5];
void multif(vector<vector<int> > &M, bool self = false) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                if (self) temp[i][j] = (temp[i][j] + (M[k][j] * M[i][k])) % (MOD - 1);
                else temp[i][j] = (temp[i][j] + (M[k][j] * transf[i][k])) % (MOD - 1);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] = temp[i][j];
        }
    }
    return;
}
void multic(vector<vector<int> > &M, bool self = false) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                if (self) temp[i][j] = (temp[i][j] + (M[k][j] * M[i][k])) % (MOD - 1);
                else temp[i][j] = (temp[i][j] + (M[k][j] * transc[i][k])) % (MOD - 1);
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            M[i][j] = temp[i][j];
        }
    }
    return;
}
vector<vector<int> > F = transf, C = transc;
void init() {
	// initialize
    
}
void multiply(int n) {
    if (n == 1) return;
    multiply((n >> 1));
    multif(F, true);
    multic(C, true);
    if (n & 1) {
        multif(F, false);
        multic(C, false);
    }
    return;
}
int bigmod(int n, int p) {
    if (p == 0) return 1;
    else if (p == 1) return n;
    int h = bigmod(n, (p >> 1));
    h = (h * h) % MOD;
    if (p & 1) h = (h * n) % MOD;
    return h;
}
void solve(int case_no) {
	// solve
    int n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    multiply(n - 3);
    int f1expo = F[0][2];
    int f2expo = F[1][2];
    int f3expo = F[2][2];
    int cexpo = (3 * C[3][2] + 1 * C[4][2]) % (MOD - 1);
    debug(f1expo, f2expo, f3expo, cexpo);
    int ans = 1;
    ans *= bigmod(f1, f1expo);
    ans %= MOD;
    ans *= bigmod(f2, f2expo);
    ans %= MOD;
    ans *= bigmod(f3, f3expo);
    ans %= MOD;
    ans *= bigmod(c, cexpo);
    ans %= MOD;
    cout << ans << endl;
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	init();
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
}
/*

*/