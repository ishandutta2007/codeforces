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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    string t;
    forn (i, 0, sz(s)) 
    	if (s[i] != 'a')
    		t += s[i];
    if (sz(t) % 2)
    	return cout << ":(", 0;
   	for (int i = 0; i < sz(t) / 2; i++) 
   		if (t[i] != t[i + sz(t) / 2])
   			return cout << ":(", 0;
   	forn (i, sz(s) - sz(t) / 2, sz(s))
   		if (s[i] == 'a')
   			return cout << ":(", 0;
   	forn (i, 0, sz(s) - (sz(t) / 2))
   		cout << s[i];
    return 0;
}