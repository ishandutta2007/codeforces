#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=(1<<20)+5, INF=2e9+5, mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, x;
        cin>>n>>x>>m;
        int la=x, ra=x;
        for(int i=0; i<m; i++){
            int l, r;
            cin>>l>>r;
            if(l<=ra && r>=la){
                la=min(l, la);
                ra=max(r, ra);
            }
        }
        cout<<(ra-la)+1<<"\n";
    }
}