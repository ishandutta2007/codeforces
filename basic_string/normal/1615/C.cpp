#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char a[N],b[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,s11,s00,s01,s10,ans;
	for(cin>>T;T--;){
		cin>>n;s11=s00=s01=s10=0;
		cin>>a+1>>b+1;
		for(i=1;i<=n;++i){
			if(a[i]=='1'){
				if(b[i]=='1')++s11;else ++s10;
			}else{
				if(b[i]=='1')++s01;else ++s00;
			}
		}
		ans=1e9;
		if(s11-s00==1)ans=min(ans,s00+s11);
		if(s10==s01)ans=min(ans,s10+s01);
		if(ans>N)cout<<-1<<'\n';else cout<<ans<<'\n';
	}
	return 0;
}