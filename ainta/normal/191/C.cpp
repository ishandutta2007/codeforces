#include<stdio.h>
#include<algorithm>
using namespace std;
int t,n,a,s[200001],l[200001],v[200001],b[200001],c,r[200001],p[200001],pp[200001],Dep[200001],x,j,q,tt,rr[200001],ttt,ss[200001];
int st[200001],sz[200001],top,R[200001],R2[200001],Res[200001],P[200001];
struct A{int a,b,c;bool operator()(A p,A q){return p.a<q.a;}}w[200001];
int main(){
	int i,y,z;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&w[i*2].a,&w[i*2].b);
		w[i*2].c=w[i*2+1].c=i+1;
		w[i*2+1].b=w[i*2].a,w[i*2+1].a=w[i*2].b;}
	stable_sort(w,w+n*2-2,A());
	tt=w[0].a,s[tt]=0;
	for(i=1;i<n*2-2;i++){
		if(tt!=w[i].a)l[tt]=i,tt=w[i].a,s[tt]=i;}
	l[tt]=n*2-2;
	top=0;
	c=0;
	v[1]=1,st[++top]=1,sz[top]=s[0],r[1]=++c;
	while(top>0){
		if(sz[top]==l[st[top]]){b[r[st[top]]]=c;top--;continue;}
		y=w[sz[top]].b;
		if(v[y]==0){
			P[++c]=w[sz[top]].c;Dep[c]=Dep[r[st[top]]]+1;p[c]=r[st[top]];v[y]=1;sz[top]++;st[++top]=y,sz[top]=s[y],r[y]=c;
		}
		else sz[top]++;}
	for(i=0;i<n;i++)rr[r[i]]=i;
	for(i=1;i<=n;i++){
		if(Dep[i]>=300){
				x=i;
				for(j=0;j<300;j++)x=p[x];
				pp[i]=x;}
		else pp[i]=0;}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&y,&z);
		y=r[y],z=r[z];
		tt=y;
		while(pp[tt]>0&&(pp[tt]>z||b[pp[tt]]<z)){
			R[tt]++;
			tt=pp[tt];
		}
		while(tt>z||b[tt]<z){
			R2[tt]++;
			tt=p[tt];
		}
		ttt=z;
		while(pp[ttt]>0&&pp[ttt]>tt){R[ttt]++,ttt=pp[ttt];}
		while(ttt!=tt){R2[ttt]++,ttt=p[ttt];}}
	for(i=1;i<=n;i++){
		if(R[i]){
			tt=i,ttt=0;
			while(ttt<300){
				Res[P[tt]]+=R[i];
				tt=p[tt];ttt++;}}
		if(R2[i])Res[P[i]]+=R2[i];
	}
	for(i=1;i<n;i++)printf("%d ",Res[i]);
}