#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e3+5;

int T;
int n;
int a[N],q[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n<<=1;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int p=1,m=0;
		for(int i=2;i<=n+1;++i)
		if(i==n+1||a[i]>a[p]){
			q[++m]=i-p;
			p=i;
		}
		static int f[N][N];
		for(int i=0;i<=m;++i)
		for(int j=0;j<=n;++j){
			f[i][j]=0;
		}
		f[0][n/2]=1;
		for(int i=0;i<m;++i)
		for(int j=0;j<=n;++j)
		if(f[i][j]){
			if(j+q[i+1]<=n)f[i+1][j+q[i+1]]=1;
			if(j-q[i+1]>=0)f[i+1][j-q[i+1]]=1;
		}
		if(f[m][n/2])puts("YES");
		else puts("NO");
	}
}