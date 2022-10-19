#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mxp,res;
pair<int,int>p[1001000];
set<int>s;
signed main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&p[i].first);
		if(p[mxp].first<p[i].first)mxp=i;
	}
	for(int i=0;i<n;i++)p[i].second=(i-mxp+n)%n,p[i].first*=-1;
	sort(p,p+n);
	for(int i=0,j=0;i<n;){
		while(j<n&&p[j].first==p[i].first)j++;
		int sz=s.size(),cnt=0,prev=-1;
		if(!sz)res+=(j-i)*(j-i-1)/2;
		else for(int k=j-1;k>=i;k--){
			int cur=*(--s.lower_bound(p[k].second));
			if(cur!=prev)prev=cur,res+=cnt*(cnt-1)/2+cnt*min(sz,2ll),cnt=0;
			cnt++;
		}
		res+=cnt*(cnt-1)/2+cnt*min(sz,2ll),cnt=0;
		for(int k=i;k<j;k++)s.insert(p[k].second);
		i=j;
	}
	printf("%lld\n",res);
	return 0;
}