#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=1003;
int a[N],b[N],p[M],n,m;
char s[N],r[N],t[M];
bool v[M];
void work(char*s,int*a){
	int i=2,j=0;
	for(;i<=m;p[i++]=j){
		while(j&&t[j+1]!=t[i])j=p[j];
		if(t[j+1]==t[i])++j;
	}
	for(i=1,j=0;i<=n;a[i++]=j){
		while(j&&t[j+1]!=s[i])j=p[j];
		if(t[j+1]==s[i])++j;
	}
}
int main(){
	int i,q,w=0;
	scanf("%s%d",s+1,&q),n=strlen(s+1),memcpy(r,s,n+1),reverse(r+1,r+n+1);
	while(q--){
		if(scanf("%s",t+1),m=strlen(t+1),m>1){
			memset(v,0,m+1),work(s,a),reverse(t+1,t+m+1),work(r,b);
			for(i=1;i<=n;v[a[i]]=1,++i)if(v[m-b[n-i+1]]){
				++w;
				break;
			}
		}
	}
	printf("%d",w);
	return 0;
}