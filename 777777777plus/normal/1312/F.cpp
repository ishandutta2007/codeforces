#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const int M = 1e2+5;

int T;
int n,w[3];
int f[M][3],vis[M];
int l[N],r[N];
ll a[N],m;

bool check(int n){
	for(int i=0;i<n;++i)if(f[100-i][0]!=f[100-i-n][0])return 0;
	return 1;
}

int calf(ll x,int t){
	if(x<=100)return f[x][t];
	return f[(x-100)%m+100-m][t];
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>w[0]>>w[1]>>w[2];
		f[0][0]=f[0][1]=f[0][2]=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=1e2;++i)
		for(int j=0;j<3;++j){
			static int cnt;
			++cnt;
			for(int k=0;k<3;++k){
				if(j&&j==k)continue;
				vis[f[max(i-w[k],0)][k]]=cnt;
			}
			f[i][j]=0;
			while(vis[f[i][j]]==cnt)f[i][j]++;
		}
		for(int i=20;i>=1;--i)
		if(check(i)){
			m=i;
			break;
		}
		for(int i=1;i<=n;++i){
			cin>>a[i];
			l[i]=r[i]=calf(a[i],0);
		}
		l[0]=r[n+1]=0;
		for(int i=2;i<=n;++i)l[i]^=l[i-1];
		for(int i=n-1;i>=1;--i)r[i]^=r[i+1];
		if(!l[n]){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int x=l[i-1]^r[i+1];
			for(int j=0;j<3;++j){
				int y=x^calf(max(a[i]-w[j],0ll),j);
				if(!y)ans++;
			}
		}
		cout<<ans<<endl;
	}
}