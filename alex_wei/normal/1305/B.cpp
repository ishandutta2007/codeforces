#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int pre[1005],suf[1005];
signed main(){
	cin>>s;
	for(int i=0;i<s.size();i++)pre[i]=(i==0?0:pre[i-1])+(s[i]=='(');
	for(int i=s.size()-1;~i;i--)suf[i]=(suf[i+1])+(s[i]==')');
	int ans=0,ans2;
	for(int i=1;i<s.size();i++)ans=max(ans,min(pre[i-1],suf[i]));
	if(!ans)puts("0"),exit(0);
	cout<<1<<endl<<ans*2<<endl;
	ans2=ans;
	for(int i=0;i<s.size();i++){
		if(ans&&s[i]=='(')cout<<i+1<<" ",ans--;
	}
	int p[1005],cnt=0;
	for(int i=s.size()-1;~i;i--){
		if(ans2&&s[i]==')')p[++cnt]=i+1,ans2--;
	}
	for(int i=cnt;i;i--)cout<<p[i]<<" ";
	return 0;
}