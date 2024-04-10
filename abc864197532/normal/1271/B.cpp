#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	int n;
	string s;
	cin >> n >> s;
	vector <int> nums;
	int a = 0;
	fop (i,0,n) {
		if (s[i] == 'B') a++;
	}
	if (a & 1 and !(n & 1)) {
		cout << -1 << endl;
		return 0;
	}
	if (a & 1) {
		fop (i,0,n-1) {
			if (s[i] == 'W') {
				s[i] = 'B';
				s[i+1] = 'B' + 'W' - s[i+1];
				nums.pb(i);
			}
		}
	} else {
		fop (i,0,n-1) {
			if (s[i] == 'B') {
				s[i] = 'W';
				s[i+1] = 'B' + 'W' - s[i+1];
				nums.pb(i);
			}
		}
	}
	cout << nums.size() << endl;
	fop (i,0,nums.size()) cout << nums[i]+1 << " \n"[i == nums.size()-1];
}