#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,m;
int l[N][26],r[N][26],sl[N],sr[N];
char s[N],t[N];

int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(int j=0;j<26;++j)r[n+1][j]=n+1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<26;++j)r[i][j]=r[i+1][j];
		r[i][s[i]-'a']=i;
	}
	for(int j=0;j<26;++j)l[0][j]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)l[i][j]=l[i-1][j];
		l[i][s[i]-'a']=i;
	}
	int p=0;
	for(int i=1;i<=m;++i){
		p=r[p+1][t[i]-'a'];
		sl[i]=p;
	}
	p=n+1;
	for(int i=m;i>=1;--i){
		p=l[p-1][t[i]-'a'];
		sr[i]=p;
	}
	int ans=0;
	for(int i=1;i<m;++i){
		ans=max(ans,sr[i+1]-sl[i]);
	}
	printf("%d\n",ans);
}