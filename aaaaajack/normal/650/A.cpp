#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> x,y;
	map<pair<int,int>,int> xy;
	int n,tx,ty;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&tx,&ty);
		x[tx]++;
		y[ty]++;
		xy[make_pair(tx,ty)]++;
	}
	for(auto it=x.begin();it!=x.end();++it){
		ans+=1LL*(it->second)*(it->second-1)/2;
	}
	for(auto it=y.begin();it!=y.end();++it){
		ans+=1LL*(it->second)*(it->second-1)/2;
	}
	for(auto it=xy.begin();it!=xy.end();++it){
		ans-=1LL*(it->second)*(it->second-1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}