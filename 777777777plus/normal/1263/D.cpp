#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+1e2+5;

int n,fa[N];
char s[N];

int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<N;++i)fa[i]=i; 
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int m=strlen(s+1);
		for(int j=1;j<=m;++j)fa[gf(i)]=fa[gf(n+s[j])];
	}
	static bool a[N];
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=gf(i);
		if(!a[x])ans++;
		a[x]=1;
	}
	cout<<ans<<endl;
}