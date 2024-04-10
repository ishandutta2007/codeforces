#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int mat[710],n,f[710][710][3][3],res;
char s[710];
stack<int>stk;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='(')stk.push(i);
		else mat[stk.top()]=i,mat[i]=stk.top(),stk.pop();
	}
	for(int i=1;i<n;i++)if(mat[i]==i+1)f[i][i+1][0][2]=f[i][i+1][2][0]=f[i][i+1][1][2]=f[i][i+1][2][1]=1;
	for(int l=4;l<=n;l+=2)for(int i=1,j=i+l-1;j<=n;i++,j++){
		if(s[i]!='('||s[j]!=')')continue;
		if(mat[i]==j){
			for(int a=0;a<3;a++)for(int b=0;b<3;b++){
				if(a==b)continue;
				if(a!=2&&b!=2)continue;
				for(int c=0;c<3;c++)for(int d=0;d<3;d++){
					if(a!=2&&c!=2&&a==c)continue;
					if(b!=2&&d!=2&&b==d)continue;
					(f[i][j][a][b]+=f[i+1][j-1][c][d])%=mod;
				}
			}
		}else{
			int k=mat[j];
			for(int a=0;a<3;a++)for(int b=0;b<3;b++)for(int c=0;c<3;c++)for(int d=0;d<3;d++){
				if(b!=2&&c!=2&&b==c)continue;
				f[i][j][a][d]=(1ll*f[i][k-1][a][b]*f[k][j][c][d]+f[i][j][a][d])%mod;
			}		
		}
	}
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)(res+=f[1][n][i][j])%=mod;
	printf("%d\n",res);
	return 0;
}