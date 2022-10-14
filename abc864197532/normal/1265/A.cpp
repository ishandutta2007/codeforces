#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool is = true;
		fop (i,0,s.length()-1) {
			if (s[i] == s[i+1] and s[i] != '?') {
				is = false;
			}
		}
		if (!is) {
			cout << -1 << endl;
			continue; 
		}
		if (s[0] == '?') {
			if (s[1] == 'a') s[0] = 'b';
			else s[0] = 'a';
		}
		fop (i,1,s.length()-1) {
			if (s[i] != '?') continue;
			if (s[i+1] == '?') {
				if (s[i-1] == 'a') s[i] = 'b';
				else s[i] = 'a';
			} else {
				if (s[i-1] == s[i+1]) {
					if (s[i-1] == 'a') s[i] = 'b';
					else s[i] = 'a';
				} else {
					s[i] = 'a' - s[i-1] + 'b' - s[i+1] + 'c';
				}
			}
		}
		if (s[s.length()-1] == '?') {
			if (s[s.length()-2] == 'a') s[s.length()-1] = 'b';
			else s[s.length()-1] = 'a';
		}
		cout << s << endl;
	}
}