#include<bits/stdc++.h>
#define N 1001000
using namespace std;
char s[N];
int main(){
	int ans=0,n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int pre=0,pos=0;
	for(int i=1;i<=n;i++){
		if(s[i]==')') pre--;
		else pre++;
		if(pre==0) {
			if(s[i]=='(') ans+=i-pos;
			pos=i;
		}
	}
	if(pre==0) printf("%d\n",ans);
	else puts("-1");
	return 0;
}