#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,jum[100100],mxp[100100],muj[100100];
pair<int,int>p[100100];
ll res,val[100100];
int MAX(int x,int y){return jum[x]>jum[y]?x:y;}
priority_queue<pair<int,int> >q;
pair<ll,int>mn=make_pair(0x3f3f3f3f,0);
int main(){
//	freopen("I.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(p[mid].first-p[i].first<=p[i].second)l=mid;
			else r=mid-1;
		}
		jum[i]=l,mxp[i]=MAX(mxp[i-1],i);
	}
	for(int i=n;i;i--)muj[i]=max(muj[jum[mxp[i]]],i),q.push(make_pair(p[i].first+p[i].second,i));
	for(int i=n;i;i--){
		if(muj[i]==n)continue;
		if(muj[i]>i){val[i]=val[muj[i]];continue;}
		while(q.top().second>muj[i])q.pop();
		for(int j=muj[i+1];j>muj[i];j--)mn=min(mn,make_pair(val[j]+p[j].first,j));
		val[i]=mn.first-q.top().first;
	}
//	for(int i=1;i<=n;i++)printf("%d ",muj[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",val[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d %d\n",p[i].first,p[i].second);
	res=val[1];
	for(int i=1;i<=n;i++)res+=p[i].second;
	printf("%lld\n",res);
	return 0;
}
/*
5
0 4
3 1
2 3
0 5
6 4
*/