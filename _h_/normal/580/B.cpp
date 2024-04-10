#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef pair<int,int> pii;
typedef long long ll;
int main(){
	int n,d;
	ll cur = 0, ans = 0;
	scanf("%d%d",&n,&d);
	vector<pii> fr(n);
	rep(i,0,n) scanf("%d %d",&fr[i].first,&fr[i].second);
	sort(fr.begin(),fr.end());
	int bak = 0, fram = 0;
	while(bak < n){
		while(fram < n && fr[fram].first < fr[bak].first+d){
			cur += fr[fram++].second;
		}
		ans = max(ans, cur);
		cur -= fr[bak++].second;
	}
	printf("%lld\n",ans);
}