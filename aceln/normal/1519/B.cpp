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
        int n,m,k; cin>>n>>m>>k;
        int sum=0,x=1,y=1;
        while (x<n) {
            sum+=y;
            x++;
        }
        while (y<m) {
            sum+=x;
            y++;
        }
        if (k==sum) cout<<"YES\n";
        else cout<<"NO\n";
    }
}