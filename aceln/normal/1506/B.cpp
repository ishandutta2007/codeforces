#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while (t--) {
		int n,k;
		cin>>n>>k;
		string s; cin>>s;

		int las=-1,mx=-1,ans=0,lass=-1;
		for (int i=0;i<n;i++) {
			char c=s[i];
			if (c=='*') {
				if (las==-1) las=i,ans++;
				else if (i-las>k) las=lass,ans++;
				mx=max(mx,i);
				lass=i;
			}
		}
		cout<<(mx==las ? ans : ans+1)<<'\n';
	}
}