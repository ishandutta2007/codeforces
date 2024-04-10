#include<bits/stdc++.h>
#define N 100100
using namespace std;
int val[N];
bool ud[N];
int main(){
	int n,k,r=0,c;
	char s[100];
	bool finish=true;
	scanf("%d%d",&n,&k);
	c=n+1;
	for(int i=0;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='?') ud[i]=true,finish=false,--c;
		else sscanf(s,"%d",&val[i]);
	}
	if(finish){
		if(k==0) puts(val[0]?"No":"Yes");
		else{
			for(int i=0;i<=n;i++){
				r+=val[i];
				if(r%k) break;
				r/=k;
			}
			if(r) puts("No");
			else puts("Yes");
		}
	}
	else{
		if(k==0){
			if(ud[0]) puts(c&1?"Yes":"No");
			else puts(val[0]?"No":"Yes");
		}
		else if(n&1) puts("Yes");
		else puts("No");
	}
	return 0;
}