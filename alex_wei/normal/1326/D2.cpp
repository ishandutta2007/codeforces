#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) v.begin(),v.end()
#define sor(v) sort(all(v))
#define rev(v) reverse(all(v))
#define mem(v,x) memset(v,x,sizeof(v))
 
const int N=1e6+5;
const ll mod=1e9+7,mod2=998244353;
const ll bs=131,bs2=37;
int t;
string s;
ll pw[N],pw2[N],hs[N],hs2[N],hsrv[N],hsrv2[N];
pii get(int l,int r){
	return {((hs[r]-hs[l-1]*pw[r-l+1])%mod+mod)%mod,((hs2[r]-hs2[l-1]*pw2[r-l+1])%mod2+mod2)%mod2};
}
pii getrv(int l,int r){
	return {((hsrv[l]-hsrv[r+1]*pw[r-l+1])%mod+mod)%mod,((hsrv2[l]-hsrv2[r+1]*pw2[r-l+1])%mod2+mod2)%mod2};
}
bool para(int l,int r){
	pii x=get(l,r),y=getrv(l,r);
	return x.fi==y.fi&&x.se==y.se;
}
void solve(){
	cin>>s;
	for(int i=1;i<=s.size();i++){
		hs[i]=(hs[i-1]*bs+s[i-1]-'a')%mod;
		hs2[i]=(hs2[i-1]*bs2+s[i-1]-'a')%mod2;
	}
	hsrv[s.size()+1]=hsrv2[s.size()+1]=0;
	for(int i=s.size();i;i--){
		hsrv[i]=(hsrv[i+1]*bs+s[i-1]-'a')%mod;
		hsrv2[i]=(hsrv2[i+1]*bs2+s[i-1]-'a')%mod2;
	}
	int l=1,r=s.size();
	while(s[l-1]==s[r-1]&&l<r)l++,r--;
	if(l>=r){
		cout<<s<<endl;
		return;
	}
	int len=0,tg=0;
	for(int i=1;l+i-1<=r;i++)if(para(l,l+i-1))len=i,tg=0;
	for(int i=1;r-i+1>=l;i++)if(para(r-i+1,r)&&i>len)len=i,tg=1;
	for(int i=1;i<l;i++)cout<<s[i-1];
	if(tg)for(int i=len;i;i--)cout<<s[r-i];
	else for(int i=0;i<len;i++)cout<<s[l+i-1];
	for(int i=r+1;i<=s.size();i++)cout<<s[i-1];
	cout<<endl;
}
int main(){
	cin>>t;
	pw[0]=pw2[0]=1;
	for(int i=1;i<N;i++)pw[i]=(pw[i-1]*bs)%mod,pw2[i]=(pw2[i-1]*bs2)%mod2;
	while(t--)solve();
	return 0;
}