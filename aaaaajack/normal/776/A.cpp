#include<bits/stdc++.h>
#define N 20
using namespace std;
char s1[N],s2[N],tmp[N],nxt[N];
int main(){
	scanf("%s%s",s1,s2);
	printf("%s %s\n",s1,s2);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s",tmp,nxt);
		if(strcmp(s1,tmp)==0) memcpy(s1,nxt,N-1);
		else memcpy(s2,nxt,N-1);
		printf("%s %s\n",s1,s2);
	}
	return 0;
}