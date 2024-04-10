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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    string ans="";
    for (int i=0;i<k;i++) ans.pb('z');

    for (int i=1;i<=n;i++) {
        string tmp="";
        for (int j=0;j<k;j++)
            tmp.pb(s[j%i]);
        if (ans>tmp) ans=tmp;
    }
    cout<<ans<<'\n';
}