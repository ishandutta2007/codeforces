#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int S=26;

int n,q,len,k,cnt,p[N];
char s[N],t[N];
bitset <N> c[S],ans;

int main(){
	scanf("%s%d",s,&q),n=strlen(s);
	for(int i=0;i<n;i++)c[s[i]-'a'][i]=1;
	while(q--){
		scanf("%d%s",&k,t),ans.set(),len=strlen(t),cnt=0;
		for(int i=0;i<len;i++)ans&=c[t[i]-'a']<<len-i-1;
		for(int it=ans._Find_first();it!=N;it=ans._Find_next(it))p[++cnt]=it;
		int ans=1e9; for(int i=k;i<=cnt;i++)ans=min(ans,p[i]-p[i-k+1]);
		cout<<(ans==1e9?-1:ans+len)<<endl;
	}
	return 0;
}