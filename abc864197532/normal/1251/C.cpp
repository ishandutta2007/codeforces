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
		string s,even="",odd="";
		cin >> s;
		string ans="";
		fop (i,0,s.length()) {
			if((s[i] - '0') % 2) even += s[i];
			else odd += s[i];
		}
		int i,j;
		for (i=0, j=0;i < even.length() && j < odd.length();) {
			if (even[i] < odd[j]) {
				ans += even[i];
				i++;
			} else {
				ans += odd[j];
				j++;
			}
		}
		fop (k,i,even.length()) {
			ans += even[k];
		}
		fop (k,j,odd.length()) {
			ans += odd[k];
		}
		cout << ans << endl;
	} 
}