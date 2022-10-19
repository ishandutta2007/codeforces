#include<bits/stdc++.h>
using namespace std;
int n,a[1010],p[1010];
char s[1010][1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,[](int x,int y){return a[x]>a[y];});
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n;j++)s[i][j]='0';
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n+1&&a[p[i]];j++,a[p[i]]--)s[j][p[i]]='1';
		for(int j=1;a[p[i]];j++,a[p[i]]--)s[j][p[i]]='1';
	}
	printf("%d\n",n+1);
	for(int i=1;i<=n+1;i++)printf("%s\n",s[i]+1);
	return 0;
}