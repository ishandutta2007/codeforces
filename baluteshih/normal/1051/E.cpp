#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=998244353;
string a,l,r;
ll dp[1000001],sdp[1000001];
int zl[2000005],zr[2000005];

void Z_value(int *z,string s){
	int L=0,R=0;
	for(int i=1;i<s.size();i++){
		if(i>R){
			L=R=i;
			while(R<s.size() && s[R-L]==s[R]) ++R;
			z[i]=R-L;R--;
		}
		else{
			int k=i-L;
			if(z[k]<R-i+1) z[i]=z[k];
			else{
				L=i;
				while(R<s.size() && s[R-L]==s[R]) ++R;
				z[i]=R-L,R--;
			}
		}
	}
}

ll cal(ll l,ll r)
{
	if(l>r) return 0;
	if(l==0) sdp[r];
	return (sdp[r]-sdp[l-1]+MOD)%MOD;
}

int main()
{jizz
	int i,j,k,x,y,flag=0;
	cin >> a >> l >> r;
	if(l=="0") flag=1;
	Z_value(zr,r+"&"+a);
	Z_value(zl,l+"&"+a);
	sdp[0]=dp[0]=1;
	for(i=1;i<l.size() && i<=a.size();++i)
		sdp[i]=1;
	for(j=l.size()+1;i<r.size() && i<=a.size();++i,++j)
	{
		if(zl[j]==l.size()||l[zl[j]]<a[i-l.size()+zl[j]]) dp[i]=cal(0,i-l.size());
		else dp[i]=cal(0,i-l.size()-1);
		if(flag&&a[i-1]=='0') dp[i]=(dp[i]+dp[i-1])%MOD;
		if(i==a.size()||a[i]!='0') sdp[i]=(sdp[i-1]+dp[i])%MOD;
		else sdp[i]=sdp[i-1];
	}
	for(k=r.size()+1;i<=a.size();++i,++j,++k)
	{
		if(zl[j]==l.size()||l[zl[j]]<a[i-l.size()+zl[j]]) y=i-l.size();
		else y=i-l.size()-1;
		if(zr[k]==r.size()||r[zr[k]]>a[i-r.size()+zr[k]]) x=i-r.size();
		else x=i-r.size()+1;
		dp[i]=cal(x,y);
		if(flag&&a[i-1]=='0') dp[i]=(dp[i]+dp[i-1])%MOD;
		if(i==a.size()||a[i]!='0') sdp[i]=(sdp[i-1]+dp[i])%MOD;
		else sdp[i]=sdp[i-1];
	}
	cout << dp[a.size()] << "\n";
}