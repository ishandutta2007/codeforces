#include<bits/stdc++.h>
#define N 200100
using namespace std;
char s[N];
int sum[N][26];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			sum[i][j]=sum[i-1][j];
		}
		sum[i][s[i]-'a']++;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r || s[l]!=s[r]) puts("Yes");
		else{
			int c=0;
			for(int j=0;j<26;j++){
				if(sum[r][j]>sum[l-1][j]) c++;
			}
			if(c>2) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}