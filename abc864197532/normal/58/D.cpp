#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
vector <string> ss[10],ans;
char d;

bool bigger (string s1,string s2) {
	if (s1<s2) return true;
	return false;
}

int main () {
	int n,all=0;
	cin >> n;
	string s;
	fop (i,0,n) {
		cin >> s;
		ss[s.length()-1].pb(s);
		all+=s.length();
	}
	cin >> d;
	all*=2;
	all/=n;
	all-=2;
	fop (i,0,10) {
		if (ss[i].size()>1) {
			sort(ss[i].begin(),ss[i].end());
		}
	}
	fop (i,0,10) {
		while (ss[i].size()) {
			if (all!=i*2) {
				if (bigger(ss[i][0]+d+ss[all-i][0],ss[all-i][0]+d+ss[i][0])) {
					ans.pb(ss[i][0]+d+ss[all-i][0]);
				} else {
					ans.pb(ss[all-i][0]+d+ss[i][0]);
				}
			} else {
				if (bigger(ss[i][0]+d+ss[i][1],ss[i][1]+d+ss[i][0])) {
					ans.pb(ss[i][0]+d+ss[i][1]);
				} else {
					ans.pb(ss[i][1]+d+ss[i][0]);
				}
			}
			ss[i].erase(ss[i].begin());
			ss[all-i].erase(ss[all-i].begin());
		}
	}
	sort(ans.begin(),ans.end());
	fop (i,0,n/2) {
		cout << ans[i] << endl;
	}
}