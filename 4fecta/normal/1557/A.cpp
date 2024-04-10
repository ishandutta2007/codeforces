// Problem: A. Ezzat and Two Subsequences
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();
    
    int t;
    cin >> t;
    while (t--) {
    	int n, a[100005];
    	cin >> n;
    	for (int i = 1; i <= n; i++) cin >> a[i];
    	sort(a + 1, a + n + 1);
    	int sum = 0;
    	for (int i = 1; i < n; i++) sum += a[i];
    	printf("%.8f\n", (double) sum / (n - 1) + a[n]);
    }

    return 0;
}