#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int now=0,k=0,tmp=1,ans=0;
		fop (i,0,s.length()) {
			now++;
			if (s[i]=='1') {
				k=i;
				tmp=1;
				ans++;
				while (true) {
					k++;
					if (k>=s.length()) break;
					tmp*=2;
					tmp+=(s[k]-'0');
					if (now+k-i<tmp) break;
					ans++;
				}
				now=0;
			}
		}
		cout << ans << endl;
	}
}