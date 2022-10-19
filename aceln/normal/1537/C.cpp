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
        int n; cin>>n;
        vector<int> v(n);
        for (int &i:v) cin>>i;

        sort(all(v));
        int minn=inf,idx;
        for (int i=0;i<n-1;i++) {
            if (v[i+1]-v[i]<minn) {
                minn=v[i+1]-v[i];
                idx=i;
            }
        }
        cout<<v[idx];
        for (int i=idx+2;i<n;i++) cout<<' '<<v[i];
        for (int i=0;i<idx;i++) cout<<' '<<v[i];
        cout<<' '<<v[idx+1]<<'\n';
    }
}