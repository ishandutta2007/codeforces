#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;
vii ans;
void make_eq(int a, int b){
    if(a==b)return;
    //cout<<a<<" "<<b<<"\n";
    int m=(a+b)/2;
    make_eq(a, m);
    make_eq(m+1, b);
    for(int i=0; i<=m-a; i++){
        ans.pb(mp(i+a, m+1+i));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int i;
    for(i=1; ; i*=2)if(i*2>n){make_eq(1, i); make_eq(n-i+1, n); break;}
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.st<<" "<<i.nd<<"\n";
    }
}