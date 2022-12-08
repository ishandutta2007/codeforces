#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int n,k;
int a[N][7],c[N][10],ans[N];
int f[10][7];
bool can[N][N];

void init(int f[7],vector<int> g){
	for(int i=0;i<7;++i)f[i]=g[i];
}

int main(){
	init(f[0],{1,1,1,0,1,1,1});
	init(f[1],{0,0,1,0,0,1,0});
	init(f[2],{1,0,1,1,1,0,1});
	init(f[3],{1,0,1,1,0,1,1});
	init(f[4],{0,1,1,1,0,1,0});
	init(f[5],{1,1,0,1,0,1,1});
	init(f[6],{1,1,0,1,1,1,1});
	init(f[7],{1,0,1,0,0,1,0});
	init(f[8],{1,1,1,1,1,1,1});
	init(f[9],{1,1,1,1,0,1,1});
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		for(int j=0;j<7;++j){
			a[i][j]=s[j]-'0';
		}
	}
	for(int t=0;t<10;++t){
		for(int i=1;i<=n;++i){
			bool flag=1;
			int cnt=0;
			for(int j=0;j<7;++j){
				if(a[i][j]&&!f[t][j])flag=0;
				if(!a[i][j]&&f[t][j])cnt++;
			}
			if(flag)c[i][t]=cnt;
			else c[i][t]=-1;
		}
	}
	can[n+1][0]=1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<=k;++j)
		if(can[i+1][j]){
			for(int t=0;t<10;++t)
			if(c[i][t]!=-1){
				can[i][j+c[i][t]]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		bool flag=0;
		for(int j=9;~j;--j)
		if(c[i][j]!=-1&&k>=c[i][j]&&can[i+1][k-c[i][j]]){
			flag=1;
			ans[i]=j;
			k-=c[i][j];
			break;
		}
		if(!flag){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)printf("%d",ans[i]);
	printf("\n");
}