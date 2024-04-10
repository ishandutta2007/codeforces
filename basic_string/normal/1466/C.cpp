#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int a[2][2],c[2][2];
int main(){
	int n,i,j,k,T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),s[n+1]='A';
		if(s[1]==s[2])a[0][0]=1e9;else a[0][0]=0;
		a[0][1]=a[1][0]=1,a[1][1]=2;
		for(i=3;i<=n;++i){
			memcpy(c,a,sizeof(a)),memset(a,9,sizeof(a));
			if(s[i]==s[i-2]&&s[i]==s[i-1]){
				a[0][1]=min(c[0][0],c[1][0])+1;
				a[1][0]=c[1][1];
				a[1][1]=min(c[0][1],c[1][1])+1;
			}else if(s[i]==s[i-2]){
				a[0][0]=c[1][0];
				a[0][1]=min(c[0][0],c[1][0])+1;
				a[1][0]=c[1][1];
				a[1][1]=min(c[0][1],c[1][1])+1;
			}else if(s[i]==s[i-1]){
				a[0][1]=min(c[0][0],c[1][0])+1;
				a[1][0]=min(c[0][1],c[1][1]);
				a[1][1]=min(c[0][1],c[1][1])+1;
			}else{
				a[0][0]=min(c[0][0],c[1][0]);
				a[0][1]=min(c[0][0],c[1][0])+1;
				a[1][0]=min(c[0][1],c[1][1]);
				a[1][1]=min(c[0][1],c[1][1])+1;
			}
		}
		cout<<min(a[0][0],min(a[0][1],min(a[1][0],a[1][1])))<<'\n';
	}
	return 0;
}