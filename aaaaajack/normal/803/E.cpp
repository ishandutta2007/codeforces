#include<bits/stdc++.h>
#define N 2010
#define Q 998244353
using namespace std;
char fr[N][N];
char s[N];
char diff[10]="WDL";
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	fr[0][k]='G';
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k*2;j++){
			for(int t=-1;t<=1;t++){
				if(j+t>0 && j+t<k*2 && fr[i-1][j+t] && (s[i]=='?' || s[i]==diff[t+1])){
					fr[i][j]=diff[t+1];
				}						
			}
		}
	}
	if(!fr[n][k*2] && !fr[n][0]) puts("NO");
	else{
		int cur=fr[n][k*2]?k*2:0;
		for(int i=n;i>=1;i--){
			s[i]=fr[i][cur];
			if(s[i]=='W') cur--;
			else if(s[i]=='L') cur++;
		}
		puts(s+1);
	}
	return 0;
}