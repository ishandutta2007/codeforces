#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,ans,n[3],p[3],r[3],ord[3],tims[3],c[3];
void gt(){
	char c=getchar();
	while(c!='B'&&c!='C'&&c!='S')c=getchar();
	while(c=='B'||c=='C'||c=='S'){
		if(c=='B')r[0]++;
		if(c=='S')r[1]++;
		if(c=='C')r[2]++;
		c=getchar();
	}
}
bool cmp(int x,int y){
	return tims[x]<tims[y];
}
int main(){
	gt();
	for(int i=0;i<3;i++)scanf("%lld",&n[i]),ord[i]=i,tims[i]=(r[i]?n[i]/r[i]:1e13);
	for(int i=0;i<3;i++)scanf("%lld",&p[i]),c[i]=p[i]*r[i];
//	for(int i=0;i<3;i++)printf("%d ",tims[i]);puts("");
//	for(int i=0;i<3;i++)printf("%d ",c[i]);puts("");
//	for(int i=0;i<3;i++)printf("%d ",r[i]);puts("");
	scanf("%lld",&m),sort(ord,ord+3,cmp);
	ans=tims[ord[0]];
	if(m>c[ord[0]]*(tims[ord[1]]-tims[ord[0]])-p[ord[0]]*(n[ord[0]]%r[ord[0]]))m-=c[ord[0]]*(tims[ord[1]]-tims[ord[0]])-p[ord[0]]*(n[ord[0]]%r[ord[0]]),ans=tims[ord[1]];
	else {ans+=(m+p[ord[0]]*(n[ord[0]]%r[ord[0]]))/c[ord[0]],printf("%I64d\n",ans);return 0;}
//	printf("%lld %lld\n",ans,m);
	if(m>(c[ord[0]]+c[ord[1]])*(tims[ord[2]]-tims[ord[1]])-p[ord[1]]*(n[ord[1]]%r[ord[1]]))m-=(c[ord[0]]+c[ord[1]])*(tims[ord[2]]-tims[ord[1]])-p[ord[1]]*(n[ord[1]]%r[ord[1]]),ans=tims[ord[2]];
	else {ans+=(m+p[ord[1]]*(n[ord[1]]%r[ord[1]]))/(c[ord[0]]+c[ord[1]]),printf("%I64d\n",ans);return 0;}
//	printf("%lld %lld\n",ans,m);
	ans+=(m+p[ord[2]]*(n[ord[2]]%r[ord[2]]))/(c[ord[0]]+c[ord[1]]+c[ord[2]]),printf("%I64d\n",ans); 
	return 0;
}