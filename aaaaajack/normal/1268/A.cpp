#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define N 200100
using namespace std;
char s[N],t[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int ge=1;
	for(int i=0;s[i];i++){
		t[i]=s[i%k];
	}
	for(int i=0;s[i];i++){
		if(t[i]<s[i]){
			ge=0;
			break;
		}
		else if(t[i]>s[i]) break;
	}
	printf("%d\n",n);
	if(ge){
		puts(t);
	}
	else{
		int m=k-1;
		while(s[m]=='9'){
			s[m--]='0';
		}
		s[m]++;
		for(int i=0;s[i];i++){
			t[i]=s[i%k];
		}
		puts(t);
	}
	return 0;
}