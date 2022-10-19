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

typedef unsigned long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, mod=1e9+7;
ll pot[18];
int main(){
    pot[0]=1;
    for(int i=1; i<=19; i++){
        pot[i]=pot[i-1]*10;
    }
    ll INF=pot[19];
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        ll ans=INF;
        vector<pair<int, pii> > V;
        for(int i=0; i<10; i++){
            int s=(k+1)*i+k*(k+1)/2-9*max(i+k-9, 0);
            //cout<<i<<" "<<s<<"\n";
            if(n<s)continue;
            /*if((n-s)%(k+1))continue;
            int l=(n-s)/(k+1);
            V.pb(mp((l)/9, mp(l%9, i)));
            //cout<<(l)/9<<" "<<l%9<<" "<<i<<" "<<s<<"\n";*/
            int po=max(i+k-9, 0), prz=k+1-po;
            for(int j=0; j<16; j++){
                int l=n-s-9*j*prz;
                //if(i==9)debug(n, i, s, l, j, po, prz);
                if(l<0)break;
                if(l%(k+1))continue;
                l/=k+1;
                if(j+1+l/9>=18) continue;
                ll res=((l%9+1)*pot[l/9]-1)*pot[j+1]+pot[j+1]-10+i;
                if(po>0 && l>=9){
                    if(l%9){
                        res=res+pot[j+1+l/9]-pot[j+1];
                    }
                    else{
                        res=res+pot[j+1+l/9]-pot[j+1];
                    }
                }
                //cout<<res<<"\n";
                ans=min(ans, res);
            }
        }
        if(ans==INF)cout<<"-1\n";
        else cout<<ans<<"\n";
        /*sort(all(V));
        if(sz(V)){
            if(V[0].nd.st){cout<<V[0].nd.st;}
            for(int i=0; i<V[0].st; i++)cout<<"9";
            cout<<V[0].nd.nd<<"\n";
        }
        else{
            cout<<"-1\n";
        }*/
    }
}