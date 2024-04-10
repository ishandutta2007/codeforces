#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e2+5;

int T;
int n,m;
char s[N],t[N];
int f[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		bool flag=0;
		for(int p=1;p<=m;++p){
			for(int i=0;i<=n;++i)
			for(int j=0;j<=i;++j){
				f[i][j]=-1;
			}
			f[0][0]=0;
			for(int i=0;i<n;++i)
			for(int j=0;j<=i;++j)
			if(~f[i][j]){
				bool f1=(s[i+1]==t[j+1]);
				bool f2=(s[i+1]==t[f[i][j]+1+p]);
				f[i+1][j]=max(f[i+1][j],f[i][j]);
				if(f1){
					f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
				}
				if(f2){
					f[i+1][j]=max(f[i+1][j],f[i][j]+1);
				}
			}
			if(f[n][p]>=m-p)flag=1;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}