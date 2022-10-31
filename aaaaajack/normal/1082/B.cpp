#include<bits/stdc++.h>
using namespace std;
char s[100100];
int ss[100100],sg[100100];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='G') sg[i+1]=sg[i]+1,ss[i+1]=ss[i];
		else sg[i+1]=sg[i],ss[i+1]=ss[i]+1;
	}
	int ans=0;
	for(int i=0;s[i];i++){
		ans=max(ans,lower_bound(ss+i,ss+n+1,ss[i]+2)-(ss+i));
		//ans=max(ans,lower_bound(sg+i,sg+n+1,sg[i]+2)-(sg+i));
	}
	printf("%d\n",min(ans-1,sg[n]));
	return 0;
}