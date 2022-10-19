#include<bits/stdc++.h>
using namespace std;
int n,m,o,ord1[100100],ord2[100100];
pair<int,int>p[100100];
bool cmp1(const int &x,const int &y){
	return p[x].second==p[y].second?p[x].first<p[y].first:p[x].second>p[y].second;
}
bool cmp2(const int &x,const int &y){
	return p[ord1[x]].first==p[ord1[y]].first?x<y:p[ord1[x]].first>p[ord1[y]].first;
}
bool cho[100100];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&o);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second),ord1[i]=i;
	sort(ord1+1,ord1+n+1,cmp1);
//	for(int i=1;i<=n;i++)printf("(%d,%d)\n",p[ord1[i]].first,p[ord1[i]].second);puts("");
	for(int i=1;i<=n;i++)ord2[i]=i;
	sort(ord2+1,ord2+n-(m-o)+1,cmp2);
	int mxp=0;
//	for(int i=1;i<=n-(m-o);i++)printf("(%d,%d)\n",p[ord1[ord2[i]]].first,p[ord1[ord2[i]]].second);puts("");
	for(int i=1;i<=o;i++)mxp=max(mxp,ord2[i]),cho[ord1[ord2[i]]]=true;
	for(int i=mxp+1;i<=mxp+m-o;i++)cho[ord1[i]]=true;
	for(int i=1;i<=n;i++)if(cho[i])printf("%d ",i);puts("");
	return 0;
}
/*
5 3 2
5 6
5 8
1 3
4 3
4 11

5 3 3
10 18
18 17
10 20
20 18
20 18
*/