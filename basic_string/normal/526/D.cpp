#include<bits/stdc++.h>
using namespace std;
enum{N=1000009};
char s[N];
int p[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,i,j;
	cin>>n>>k>>s+1;
	for(i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=p[j];
		if(s[i]==s[j+1])p[i]=++j;
	}
	for(i=1,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=p[j];
		if(s[i]==s[j+1])++j;
		while(j*(k+1ll)>k*1ll*i)j=p[j];
		if(j*1ll*k>=(k-1ll)*i)cout<<1;else cout<<0;
	}
	return 0;
}