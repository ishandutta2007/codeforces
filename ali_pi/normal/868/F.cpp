#include<bits/stdc++.h>

using namespace std;

typedef long long i64;
const int N=1e5+7;
int n,k,a[N],t[N],_l,_r;
i64 f[N],g[N],s0;

void solve(int l,int r,int L,int R){
	if(l>r)return;
	int m=(l+r)>>1,p=std::min(R,m);
	i64 mv=1ll<<60;
	while(_r<m)s0+=t[a[++_r]]++;
	while(_l>p+1)s0+=t[a[--_l]]++;
	while(_r>m)s0-=--t[a[_r--]];
	while(_l<p+1)s0-=--t[a[_l++]];
	for(int i=p;i>=L;--i){
		int x=a[i];
		s0+=t[a[--_l]]++;
		if(s0+f[i-1]<mv)mv=s0+f[i-1],p=i;
	}
	g[m]=mv;
	solve(l,m-1,L,p);
	solve(m+1,r,p,R);
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)
        scanf("%d",a+i);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=k;++i){
		_l=1,_r=s0=0;
		memset(t,0,sizeof(t));
		solve(i,n,i,n);
		memcpy(f,g,sizeof(f));
	}
	cout<<f[n]<<endl;
}