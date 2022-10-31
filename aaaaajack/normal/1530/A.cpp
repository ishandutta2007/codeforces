#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	char s[1000];
	scanf("%d ",&T);
	while(T--){
		scanf("%s",s);
		char p='0';
		for(int i=0;s[i];i++){
			if(s[i]>p) p=s[i];
		}
		printf("%d\n",p-'0');
	}
	return 0;
}