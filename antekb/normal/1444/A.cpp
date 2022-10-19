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
    int t;
    cin>>t;
    while(t--){
        ll p, l;
        int q, k;
        cin>>p>>q;
        vi V;
        k=q;
        l=p;
        for(int i=2; i*i<=q; i++){
            if(!(q%i)){
                V.pb(i);
                while(!(q%i))q/=i;
            }
        }
        if((V.empty() || V.back()!=q) && q!=1)V.pb(q);
        q=k;
        ll maks=1;
        for(int i:V){
            //cout<<i<<" ";
            int cnt1=0, cnt2=0;
            ll n=1;
            while(p%i==0){
                p/=i;
                cnt1++;
                n*=i;
            }
            while(q%i==0){
                q/=i;
                n/=i;
                cnt2++;
            }
            n*=i;
            //cout<<i<<" "<<n<<"a\n";
            if(!n)maks=l;
            else{
                maks=max(maks, l/n);
            }
        }
        cout<<maks<<"\n";
    }
}