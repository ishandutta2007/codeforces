#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	pair<ll,ll> pa[3];
	trav(x, pa) cin >> x.first >> x.second;
	rep(i,0,2)
		pa[i*2].first -= pa[1].first,
		pa[i*2].second -= pa[1].second;
	if((pa[0].first+pa[2].first!=0 || pa[0].second+pa[2].second!=0)
		&& pa[0].first*pa[0].first+pa[0].second*pa[0].second == pa[2].first*pa[2].first+pa[2].second*pa[2].second)
		puts("YES");
	else
		puts("NO");
}