#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int get_dst(char a, char b) {
	if (a > b)
		swap(a, b);
	return min(b - a, a + 26 - b);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = 1e9;
    forn (i, 0, n - 4 + 1) 
    	ans = min(ans, get_dst(s[i], 'A') + get_dst(s[i + 1], 'C') + get_dst(s[i + 2], 'T') + get_dst(s[i + 3], 'G'));
    cout << ans;
    return 0;
}