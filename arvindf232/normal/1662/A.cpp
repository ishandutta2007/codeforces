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
void init() {
	// initialize

}
void solve(int case_no) {
	// solve
    int n;
    cin >> n;
    int b[11];
    for (int i = 1; i <= 10; i++) b[i] = -1;
    while (n--) {
        int bea, dif;
        cin >> bea >> dif;
        b[dif] = max(b[dif], bea);
    }
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        if (b[i] == -1) return out("MOREPROBLEMS");
        ans += b[i];
    }
    return out(ans);
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
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
}
/*

*/