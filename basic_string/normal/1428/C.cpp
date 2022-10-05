#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
char st[N],s[N];
int main(){
	int T,i,j,k,l,n,t;
	scanf("%d",&T);
	while(T--){
		t=0;
		scanf("%s",s);l=strlen(s);
		for(i=0;i<l;++i){
			if(!t)st[++t]=s[i];
			else if(s[i]=='A')st[++t]=s[i];
			else --t;
		}
		cout<<t<<'\n';
	}
	return 0;
}