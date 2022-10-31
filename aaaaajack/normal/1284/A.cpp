#include<bits/stdc++.h>
using namespace std;
char s[20][30],t[20][30];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<m;i++) scanf("%s",t[i]);
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		printf("%s%s\n",s[(x-1)%n],t[(x-1)%m]);
	}
	return 0;
}