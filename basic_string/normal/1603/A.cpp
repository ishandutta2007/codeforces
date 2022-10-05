#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N],t[N],n,pr[N],nx[N];
void add(int x){for(;x<=n;x+=x&-x)++t[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=t[x];return r;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,i,j,k;
	for(cin>>T;T--;){
		cin>>n,memset(t,0,n*4+4);
		for(i=1;i<=n;++i)cin>>a[i],pr[i]=i-1,nx[i]=i+1;
		nx[0]=1,pr[n+1]=n; 
		for(int o=1;o<=n;++o){
			for(i=pr[n+1];i;i=pr[i]){
				if(a[i]%(i-sum(i)+1)){
					add(i),nx[pr[i]]=nx[i],pr[nx[i]]=pr[i];
					goto gg;
				}
			}
			cout<<"NO\n";goto g2;
			gg:;
		}
		cout<<"YES\n";
		g2:;
	}
	return 0;
}