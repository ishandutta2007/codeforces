#include<bits/stdc++.h>
using namespace std;
int c[200100][3],T,n,res;
char s[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),res=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)c[i][j]=c[i-1][j];
			c[i][s[i]-'1']++;
		}
		for(int i=1;i<=n;i++){
			if(!c[i][0]||!c[i][1]||!c[i][2])continue;
			int l=0,r=i-1;
			while(l<r){
				int j=(l+r+1)>>1;
				if(c[i][0]-c[j][0]&&c[i][1]-c[j][1]&&c[i][2]-c[j][2])l=j;
				else r=j-1;
			}
			res=min(res,i-l);
		}
		printf("%d\n",res==0x3f3f3f3f?0:res);
	}
	return 0;
}