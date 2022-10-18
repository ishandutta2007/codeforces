#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAXC=(1LL<<32)-1;
vector<ll> v;
string s;

int main()
{jizz
	ll l,nw=1,x=0,ans=0,flag=0;
	cin >> l;
	while(l--)
	{
		cin >> s;
		if(s[0]=='f')
		{
			cin >> x;
			if(!flag)
			{
				v.pb(x),nw*=x;
				if(nw>MAXC) flag=1;
			}
			else ++flag; 
		}
		else if(s[0]=='e')
		{
			if(flag>1) --flag;
			else if(flag==1) nw/=v.back(),v.pop_back(),--flag;
			else nw/=v.back(),v.pop_back();
		}
		else
			ans+=nw;
		if(ans>MAXC) return cout << "OVERFLOW!!!\n",0;
	}
	cout << ans << "\n";
}