#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	string s;
	cin >> s;
	set <int> alp[26];
	fop (i,0,s.length()) {
		alp[s[i]-'a'].insert(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int a;
		cin >> a;
		if (a==1) {
			int b;
			char c;
			cin >> b >> c;
			alp[s[b-1]-'a'].erase(b-1);
			s[b-1]=c;
			alp[c-'a'].insert(b-1);
		} else {
			int b,c;
			cin >> b >> c;
			int ans=0;
			fop (i,0,26) {
				auto aa=alp[i].lower_bound(b-1);
				if (aa==alp[i].end()) continue;
				if (*aa<=c-1) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
}