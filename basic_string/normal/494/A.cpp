#include<bits/stdc++.h>
using namespace std;
char s[100009];
int main(){
	int n,i,t=0,w=0,l=0;
	scanf("%s",s),n=strlen(s);
	for(i=n-1;i>=0&&s[i]!='#';--i){
		if(s[i]=='('){
			--w;
			if(w<0)return puts("-1"),0;
		}
		else ++w;
	}
	w=0;
	for(i=0;i<n;++i){
		if(s[i]=='('){
			++w;
		}else if(s[i]==')'){
			--w;
			if(w<0)return puts("-1"),0;
		}else{
			++t,--w,l=w;
			if(w<0)return puts("-1"),0;
		}
	}
	for(i=1;i<t;++i)puts("1");
	printf("%d\n",w+1);
	return 0;
}