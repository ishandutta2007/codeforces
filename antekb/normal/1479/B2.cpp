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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    int n;
    cin>>n;
    vi V;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(!sz(V) || x!=V.back())V.pb(x);
    }
    vi lst(n+1, n), nxt(n);
    for(int i=sz(V)-1; i>=0; i--){
        nxt[i]=lst[V[i]];
        lst[V[i]]=i;
    }
    int cnt=0;
    int a=-1, b=-1;
    for(int i=0; i<sz(V); i++){
        //cout<<i<<" "<<a<<" "<<b<<"\n";
        if(a!=-1 && V[a]==V[i])a=i;
        else if(b!=-1 && V[b]==V[i])b=i;
        else{
            if(a==-1)a=i, cnt++;
            else if(b==-1)b=i, cnt++;
            else if(nxt[a]>nxt[b])a=i, cnt++;
            else b=i, cnt++;
        }
    }
    cout<<cnt;
}