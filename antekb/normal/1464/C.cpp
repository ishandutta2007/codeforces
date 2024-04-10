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

const int N=2e5+5, INF=1e9+5, mod=1e9+7, K=26;
int tab[K+1];
int main(){
    int n;
    ll t;
    cin>>n>>t;
    str s;
    cin>>s;
    ll sum=0;
    for(int i=0; i<n-2; i++){
        tab[s[i]-'a']++;
        sum+=(1<<(s[i]-'a'));
    }
    t+=1<<(s[n-2]-'a');
    t-=1<<(s[n-1]-'a');
    if((sum+t)&1 || t>sum || t<-sum){
        cout<<"No";
        return 0;
    }
    t=(sum-t)/2;
    for(int i=0; i<K; i++){
        if(t&(1<<i)){
            if(tab[i]){t-=(1<<i);tab[i]--;}
            else{
                cout<<"No";
                return 0;
            }
        }
        tab[i+1]+=tab[i]/2;
    }
    cout<<"Yes";
}