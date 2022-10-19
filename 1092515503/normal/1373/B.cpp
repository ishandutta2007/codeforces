#include<bits/stdc++.h>
using namespace std;
int T,S,cnt;
char s[110];
stack<char>stk;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),S=strlen(s),cnt=0;
		while(!stk.empty())stk.pop();
		for(int i=0;i<S;i++){
			if(!stk.empty()&&stk.top()!=s[i])stk.pop(),cnt++;
			else stk.push(s[i]);
		} 
		puts(cnt&1?"DA":"NET");
	}
	return 0;
}