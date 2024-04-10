#include<bits/stdc++.h>
using namespace std;
char s[100009],t[100009];
bool f[100009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,ans;
	cin>>T;
	while(T--){
		cin>>n>>(s+1)>>(t+1),ans=0;
		memset(f,0,n+1),s[n+1]=t[n+1]='2';
		for(i=1;i<=n;++i){
			if(s[i]=='1'&&t[i]=='1'){
				if(!f[i-1]&&s[i-1]=='0'&&t[i-1]=='0')++ans;
				else if(s[i+1]=='0'&&t[i+1]=='0')f[i+1]=1,++ans;
			}else if(s[i]=='0'&&t[i]=='0')++ans;
			else ans+=2;
		}cout<<ans<<'\n';
	}
	return 0;
}