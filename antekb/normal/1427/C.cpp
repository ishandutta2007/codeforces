#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;
    vi T(q+1);
    vii V(q+1);
    vi d(q+1);
    int wsk=0;
    d[0]=0;
    V[0]={1,1};
    T[0]=0;
    int maks=-INF;
    for(int i=1; i<=q; i++){
        cin>>T[i]>>V[i].st>>V[i].nd;
        while(wsk<i && T[i]-T[wsk]>2*n)maks=max(maks, d[wsk++]);
        d[i]=maks+1;
        for(int j=wsk; j<i; j++){
            if(abs(V[j].st-V[i].st)+abs(V[i].nd-V[j].nd)<=T[i]-T[j])d[i]=max(d[i], d[j]+1);
        }
        //cout<<d[i];
    }
    while(wsk<=q)maks=max(maks, d[wsk++]);
    cout<<maks;
}