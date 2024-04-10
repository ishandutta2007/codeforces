#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,M=1e5+3,P=1e9+7; 
char tt[N],ss[N];
string s;
int ps[N];
int t[27][N],q[N],d[N],e[N],a[N],f[N],id,r,x2;
int u[99][M],v[27][M],n,m,w[27][M];
void ins(char*s,int g){
	int x=0,y;
	for(;*s;++s){
		y=*s-'a';
		if(!t[y][x])t[y][x]=++id;
		x=t[y][x];
	}
	a[g]=x;
}
void qry(string s,int*w){
	int x=0,i,l=s.size();
	memset(d,0,sizeof(d));
	for(i=0;i<l;++i)x=t[s[i]-'a'][x],++d[x];
	for(i=r;i;--i)d[f[q[i]]]+=d[q[i]];
	for(i=1;i<=m;++i)w[i]=d[a[i]];
}
void get(string s){
	int x=0,i,l=s.size();
	for(i=0;i<l;++i)x=t[s[i]-'a'][x],++e[x];
	x2=x;
}
void qry2(string s,int*w){
	int x=x2,i,l=s.size();
	memcpy(d,e,sizeof(d));
	for(i=0;i<l;++i)x=t[s[i]-'a'][x],++d[x];
	for(i=r;i;--i)d[f[q[i]]]+=d[q[i]];
	for(i=1;i<=m;++i)w[i]=d[a[i]];
}
int main(){
	int i,j,k,x,y,l=0,o=1e9;
	scanf("%d%d",&n,&m);
	cin>>s;
	scanf("%s",tt+1);
	for(i=1;i<=m;++i){
		scanf("%d",ps+i);
		scanf("%s",ss),ins(ss,i);
	}
	for(i=0;i<26;++i)if(t[i][0])q[++r]=t[i][0];
	while(l!=r){
		x=q[++l],y=f[x];
		for(i=0;i<26;++i){
			if(t[i][x])f[q[++r]=t[i][x]]=t[i][y];
			else t[i][x]=t[i][y];
		}
	}
	qry(s,u[0]);
	for(i=1;i<=n;++i){
		s=s+tt[i]+s;
		qry(s,u[i]);
		if(s.size()>1000000){
			o=i;
			get(s);
			break;
		}
	}
	for(i=0;i<26;++i)qry2((char)('a'+i)+s,v[i]);
	if(o<=n){w[26][o]=1;
	for(i=o+1;i<=n;++i){
		for(j=0;j<27;++j)w[j][i]=w[j][i-1]*2%P;
		w[tt[i]-'a'][i]=(w[tt[i]-'a'][i]+1)%P;
	}}
	for(i=1;i<=m;++i){
		if(ps[i]<=o)printf("%d\n",u[ps[i]][i]);
		else{
			int ans=0;
			for(j=0;j<26;++j)ans=(ans+(v[j][i]-2ll*u[o][i])*w[j][ps[i]])%P;
			ans=(ans+u[o][i]*1ll*w[26][ps[i]])%P;
			printf("%d\n",(ans+P)%P);
		}
	}
	return 0;
}