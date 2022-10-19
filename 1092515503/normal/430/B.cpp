#include<bits/stdc++.h>
using namespace std;
int n,k,x,num[101],mx,m;
pair<int,int>p[101];
int main(){
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	p[m=1]=make_pair(num[1],1);
	for(int i=2;i<=n;i++){
		if(num[i]==num[i-1])p[m].second++;
		else p[++m]=make_pair(num[i],1);
	}
//	for(int i=1;i<=m;i++)printf("%d %d\n",p[i].first,p[i].second);
	for(int i=1;i<=m;i++){
		if(p[i].second+1<3||p[i].first!=x)continue;
		int l=i-1,r=i+1,tot=p[i].second;
		while(l&&r<=m&&p[l].first==p[r].first&&p[l].second+p[r].second>=3)tot+=p[l].second+p[r].second,l--,r++;
		mx=max(mx,tot);
	}
	printf("%d\n",mx); 
	return 0;
}