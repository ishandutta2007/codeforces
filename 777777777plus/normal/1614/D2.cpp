#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e7+5;
const int MAX_A = 2e7;
     
int n;
int c[N];
int f[N];
ll g[N];

void cmax(ll &x,ll y){
	y>x?x=y:0;
}

bool vis[N];
int p[N];

void prepare(){
	for(int i=2;i<=MAX_A;++i){
		if(!vis[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&p[j]*i<=MAX_A;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}

int main(){
	prepare();
	cin>>n;
	p[++p[0]]=MAX_A+1;
	for(int i=1,a;i<=n;++i)cin>>a,c[a]++;
	for(int i=MAX_A;i>=1;--i){
    	for(int j=1;j*i<=MAX_A;++j){
    		f[i]+=c[i*j];
    	}
		for(int j=1;p[j]*i<=MAX_A;++j){
			cmax(g[i],g[i*p[j]]-1ll*i*f[i*p[j]]);
		}
		g[i]+=1ll*i*f[i];
	}
	cout<<g[1]<<endl;
}