#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=2e9+5, mod=1e9+7;
int solve(const vector<int> &t){
    //cout<<t.size()<<"\n";
    vector<int> V;
    int sum=0, maks=0;
    int wsk=0;
    for(int i=0; i<=t.size(); i++){
        if(i>0 && (i==t.size() || __builtin_clz(t[i])!=__builtin_clz(t[i-1]))){
            if(V.size()>1){
                int k=0;
                if(t[i-1]!=0){
                    k=__builtin_clz(t[i-1]);
                    k=31-k;
                    k=(1<<k);
                }
                for(int j=0; j<V.size(); j++){
                    V[j]^=k;
                }
                sum+=V.size()-1;
                if(k)maks=max(sz(V)-1-solve(V)-max(wsk-1, 0), maks);
            }
            wsk++;
            V.clear();
        }
        if(i<t.size())V.pb(t[i]);
    }
    //cout<<sum<<" "<<maks<<"\n";
    return sum-maks;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vi V(n);
    for(int &i:V){
        cin>>i;
    }
    sor(V);
    cout<<solve(V);
}