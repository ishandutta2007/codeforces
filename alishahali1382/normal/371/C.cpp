#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 200010;

ll R;
ll need[3], n[3], p[3];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s;
	for (char ch : s){
		if (ch=='B') need[0]++;
		if (ch=='S') need[1]++;
		if (ch=='C') need[2]++;
	}
	cin>>n[0]>>n[1]>>n[2];
	cin>>p[0]>>p[1]>>p[2];
	cin>>R;
	//cerr<<need[0]<<' '<<need[1]<<' '<<need[2]<<' '<<endl;
	ll l=0, r=1e13;
	while (r-l>1){
		ll mid=(l+r)/2;
		if (R>=(max(0LL, need[0]*mid-n[0])*p[0] + max(0LL, need[1]*mid-n[1])*p[1] + max(0LL, need[2]*mid-n[2])*p[2])) l=mid;
		else r=mid;
		//cerr<<mid<<' '<<((need[0]*mid-n[0])*p[0] + (need[1]*mid-n[1])*p[1] + (need[2]*mid-n[2])*p[2])<<endl;
	}
	cout<<l<<endl;
	return 0;
}