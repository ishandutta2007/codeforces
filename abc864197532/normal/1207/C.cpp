#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		lli n,a,b;
		string s;
		cin >> n >> a >> b >> s;
		vector <int> nums;
		int now=0,tmp=0;
		fop (i,0,s.length()) {
			if (now==s[i]-'0') tmp++;
			else {
				nums.pb(tmp);
				now=1-now;
				tmp=1;
			}
		}
		nums.pb(tmp);
		lli sum=0;
		bool is=true;
		fop (i,1,nums.size()-1) {
			if (i%2==1) {
				if (is) {
					sum+=2*a;
					is=false;
				}
				sum+=(nums[i]+1)*b;
			} else {
				sum+=min(2*a,(nums[i]-1)*b);
			}
		}
		sum+=n*a+(n+1)*b;
		cout << sum << endl;
	}
}