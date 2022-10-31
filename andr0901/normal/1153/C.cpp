#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (n % 2)
    	return cout << ":(", 0;
    int cnt = 0;
    forn (i, 0, sz(s))
    	cnt += (s[i] == '(');
    int bal = 0;
    forn (i, 0, sz(s)) {
    	//cout << s << "  " << cnt << " " << bal << "\n";
    	if (s[i] == '?') {
    		if (cnt < n / 2) {
    			s[i] = '(';
    			cnt++;
    		} else {
    			s[i] = ')';
    		}
    	}
    	if (s[i] == '(') 
    		bal++;
    	else 
    		bal--;
    	if (bal < 0)
    		return cout << ":(", 0;
    	if (bal == 0 && i < sz(s) - 1)
    		return cout << ":(", 0;
    }
    if (bal != 0)
    	return cout << ":(", 0;
    cout << s;
    return 0;
}