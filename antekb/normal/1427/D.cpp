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
    int n;
    cin>>n;
    vi V(n);
    for(int &i:V){cin>>i;};
    for(int i=0; i<n; i++)V[i]--;
    vector<pair<pii, pii > > Q;
    while(true){
        vi pos(n);
        for(int i=0; i<n; i++)pos[V[i]]=i;
        int k=-1, l=-1, m=-1;
        for(int i=0; i<n-1; i++){
            if(pos[i]>pos[i+1]){
                k=pos[i];
                l=pos[i+1];
                for(m=l+1; m<k; m++){
                    if(V[m]!=V[m-1]+1)break;
                }
                break;
            }
        }

        if(k==-1)break;
        //cout<<k<<" "<<l<<" ";
        //Q.pb(mp(l, k));
        vi V2;//cout<<"a";
        for(int i=k+1; i<n; i++)V2.pb(V[i]);
        for(int i=m; i<=k; i++)V2.pb(V[i]);
        for(int i=l; i<m; i++)V2.pb(V[i]);
        for(int i=0; i<l; i++)V2.pb(V[i]);
        V=V2;
        //for(int i:V)cout<<i<<" ";
        //cout<<"\n";
        Q.pb(mp(mp(l, m-l), mp(k-m+1, n-k-1)));
    }
    cout<<Q.size()<<"\n";
    for(auto i:Q){
        int a=0;
        if(i.st.st)a++;
        if(i.nd.st)a++;
        if(i.st.nd)a++;
        if(i.nd.nd)a++;
        cout<<a<<" ";
        if(i.st.st)cout<<i.st.st<<" ";
        if(i.st.nd)cout<<i.st.nd<<" ";
        if(i.nd.st)cout<<i.nd.st<<" ";
        if(i.nd.nd)cout<<i.nd.nd<<" ";
        cout<<"\n";
    }
}