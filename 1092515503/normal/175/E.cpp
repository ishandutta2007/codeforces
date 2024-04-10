#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int na,nb,nc,ra,rb,rc,da,db,lim=1594323,num[13],sp[110],ss,tp,vp,op;
pair<double,double>p[110],rg[110],obj[110];
double v[110],f[110][110],g[110][110],ans;
bool cmp(pair<double,double>x,pair<double,double>y){
	return x.first>y.first;
}
double dp(){
	sort(obj+1,obj+op+1,cmp);
//	for(int i=1;i<=op;i++)printf("(%lf %lf)",obj[i].first,obj[i].second);puts("");
	for(int i=0;i<=op+1;i++)for(int j=0;j<=op+1;j++)f[i][j]=g[i][j]=0;
	for(int i=op;i;i--){
		for(int j=op-i;j;j--)g[i][j]=max(g[i+1][j],g[i+1][j-1]+obj[i].second);
		g[i][op-i+1]=g[i+1][op-i]+obj[i].second;
	}
	for(int i=1;i<=op;i++){
		f[i][0]=f[i-1][0]+obj[i].second;
		for(int j=1;j<i;j++)f[i][j]=max(f[i-1][j]+obj[i].second,f[i-1][j-1]+obj[i].first);
		f[i][i]=f[i-1][i-1]+obj[i].first;
	}
	double res=0;
	for(int i=na;i<=min(na+nb,op);i++)res=max(res,f[i][na]+g[i+1][nb-(i-na)]);
	return res;
}
double func(int ip){
	ss=0,tp=0,vp=0,op=0;
	v[++vp]=1e7,v[++vp]=-1e7;
	for(int i=0;i<13;i++)num[i]=ip%3,ip/=3,ss+=num[i];
	if(ss!=nc)return 0;
	for(int i=0;i<13;i++){
		if(num[i])v[++vp]=i-sqrt(rc*rc-1),v[++vp]=i+sqrt(rc*rc-1);
		for(int j=1;j<=num[i];j++)rg[++tp]=make_pair(i-sqrt(rc*rc-1),i+sqrt(rc*rc-1));
	}
//	for(int i=1;i<=tp;i++)printf("(%lf %lf)",rg[i].first,rg[i].second);puts("");
	sort(v+1,v+vp+1);
	for(int i=1;i<vp;i++){
		sp[i]=1;
		for(int j=1;j<=tp;j++)if(v[i]-rg[j].first>-eps&&v[i+1]-rg[j].second<eps)sp[i]++;
	}
//	for(int i=1;i<=vp;i++)printf("%lf ",v[i]);puts(""); 
//	for(int i=1;i<vp;i++)printf("%d ",sp[i]);puts("");
	for(int i=0;i<13;i++){
		double x=i-sqrt(ra*ra-1),y=i+sqrt(ra*ra-1);
		p[i].first=p[i].second=0;
		for(int j=1;j<vp;j++){
			double a=max(x,v[j]),b=min(v[j+1],y);
			if(a-b>eps)continue;
			p[i].first+=(b-a)*sp[j];
		}
		x=i-sqrt(rb*rb-1),y=i+sqrt(rb*rb-1);
		for(int j=1;j<vp;j++){
			double a=max(x,v[j]),b=min(v[j+1],y);
			if(a-b>eps)continue;
			p[i].second+=(b-a)*sp[j];
		}
		p[i].first*=da,p[i].second*=db;
	}
	for(int i=0;i<13;i++)for(int j=1;j<=2-num[i];j++)obj[++op]=p[i];
//	for(int i=1;i<=op;i++)printf("(%lf %lf)",obj[i].first,obj[i].second);
//	double pp=dp();
//	printf("%lf\n",pp);
//	for(int i=0;i<13;i++)printf("%d",num[i]);puts("");
	return dp();
}
int main(){
	scanf("%d%d%d%d%d%d%d%d",&na,&nb,&nc,&ra,&rb,&rc,&da,&db);
	for(int i=0;i<lim;i++)ans=max(ans,func(i));
	printf("%.8lf\n",ans);
	return 0;
}
/*
11 6 3

2 2 2

229 564

44909.86643796
*/