#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;
const ll mod = 998244353;

int T;
int n,m;
char s[N][N];
int a[N][N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(i%3==1)a[i][j]=1;
			else a[i][j]=(s[i][j]=='X');
		}
		static int l[N];
		int k=0;
		for(int i=1;i<=n;++i)if(i%3==1)l[++k]=i;
		for(int i=1;i<k;++i){
			int x=l[i],y=l[i+1];
			bool flag=0;
			for(int j=1;j<=m;++j)
			if(a[x+1][j]||a[x+2][j]){
				a[x+1][j]=a[x+2][j]=1;
				flag=1;
				break;
			}
			if(!flag){
				a[x+1][1]=a[x+2][1]=1;
			}
		}
		for(int i=l[k]+1;i<=n;++i)
		for(int j=1;j<=m;++j)
		if(a[i][j]){
			a[i-1][j]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)putchar(a[i][j]?'X':'.');
			puts("");
		}
	}
}
/*
*/