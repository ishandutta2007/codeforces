#include<bits/stdc++.h>
using namespace std;
enum{N=200009,M=300};
int n,m,x[N],y[N],bg[N],ans[N],f[M+3][M+3],s[N];
bool b[N];
void add(int k,int l,int r){
	int x=::x[k],y=::y[k];
	for(int i=l;;){
		if(i+=x,i>r)break;
		++s[i];
		if(i+=y,i>r){--s[r+1];break;}
		--s[i];
	}
}
void adsm(int k,int l){
	int o=x[k]+y[k];
	l%=o;
	int r=(l+x[k])%o;
	if(r<l){
		for(int i=r;i<l;++i)++f[o][i];
	}else{
		for(int i=r;i<o;++i)++f[o][i];
		for(int i=0;i<l;++i)++f[o][i];
	}
}
void dlsm(int k,int l){
	int o=x[k]+y[k];
	l%=o;
	int r=(l+x[k])%o;
	if(r<l){
		for(int i=r;i<l;++i)--f[o][i];
	}else{
		for(int i=r;i<o;++i)--f[o][i];
		for(int i=0;i<l;++i)--f[o][i];
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int i,j,k,l;
	for(i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(i=1;i<=m;++i){
		j=1,k=i;
		cin>>j>>k;
		if(x[k]+y[k]>M){
			if(j==1)b[k]=1,bg[k]=i;
			else b[k]=0,add(k,bg[k],i-1);
		}else{
			if(j==1)adsm(k,i),bg[k]=i;
			else dlsm(k,bg[k]);
		}
		for(j=1,k=0;j<=M;++j)k+=f[j][i%j];
		ans[i]=k;
	}
	for(i=1;i<=n;++i)if(b[i])add(i,bg[i],m);
	for(i=1;i<=m;++i)s[i]+=s[i-1];
	for(i=1;i<=m;++i)cout<<ans[i]+s[i]<<'\n';
	return 0;
}