#include<stdio.h>
#include<algorithm>
#include<queue>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
using namespace std;
struct A{
	__int64 t,s,p,a;
	bool operator <(const A &o)const{return t<o.t;}
}w[50001];
struct B{
	__int64 t,s,p,a;
	bool operator <(const B &o)const{return p<o.p;}
}w2[50001],o,tp;
priority_queue<B>Q;
__int64 INF=100000000,n,i,T,TT[50001],O[50001],tt,R,S,x;
int main()
{
	INF=INF*INF;
	fscanf(in,"%I64d",&n);
	for(i=0;i<n;i++){
		fscanf(in,"%I64d%I64d%I64d",&w[i].t,&w[i].s,&w[i].p);
		O[i]=w[i].s;
		w2[i].t=w[i].t,w2[i].s=w[i].s,w2[i].p=w[i].p;
		w2[i].a=w[i].a=i;
	}
	sort(w,w+n);
	sort(w2,w2+n);
	fscanf(in,"%I64d",&T);
	o=w2[0];
	for(i=0;i<n;i++){
		if(w[i].p==-1)break;
		tp.t=w[i].t,tp.s=w[i].s,tp.p=w[i].p,tp.a=w[i].a;
		Q.push(tp);
		tt=w[i].t;
		while(!Q.empty()&&tt+O[Q.top().a]<=w[i+1].t){
			tt+=O[Q.top().a];
			O[Q.top().a]=0;
			TT[Q.top().a]=tt;
			Q.pop();
		}
		if(!Q.empty())O[Q.top().a]-=w[i+1].t-tt;
		tt=w[i+1].t;
	}
	x=i;
	tt=T-o.t-o.s;
	if(tt==0){
		R=w2[n-1].p+2;
		w[x].p=R;
	}
	else{
		for(i=n-1;i>0;i--){
			if(w2[i].t>=T)continue;
			S+=O[w2[i].a];
			if(S==tt)break;
		}
		R=w2[i].p-1;
		while(i>0&&w2[i-1].p==R)R--,i--;
		w[x].p=R;
	}
	fprintf(out,"%I64d\n",R);
	w[n].t=w[n-1].t+INF;
	for(i=x;i<n;i++){
		tp.t=w[i].t,tp.s=w[i].s,tp.p=w[i].p,tp.a=w[i].a;
		Q.push(tp);
		tt=w[i].t;
		while(!Q.empty()&&tt+O[Q.top().a]<=w[i+1].t){
			tt+=O[Q.top().a];
			O[Q.top().a]=0;
			TT[Q.top().a]=tt;
			Q.pop();
		}
		if(!Q.empty())O[Q.top().a]-=w[i+1].t-tt;
		tt=w[i+1].t;
	}
	for(i=0;i<n;i++){
		fprintf(out,"%I64d ",TT[i]);
	}
}