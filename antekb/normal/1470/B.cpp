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

const int N=1e6+5, INF=1e9+5, mod=1e9+7;
int sito[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    iota(sito, sito+N,0);
    for(int i=2; i<=1000; i++){
        for(int j=1; j*i*i<N; j++){
            while(sito[j*i*i]%(i*i)==0){
                sito[j*i*i]/=i*i;
            }
        }
    }
    //for(int i=0; i<10; i++)cout<<sito[i]<<" ";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi V(n);
        for(int &i:V){cin>>i;i=sito[i];}
        sor(V);
        vii V2;
        int cnt=0;
        for(int i=0; i<n;i++){
            if(i>0 && V[i]>V[i-1]){
                V2.pb(mp(cnt, V[i-1]));
                cnt=0;
            }
            cnt++;
        }
        V2.pb(mp(cnt, V.back()));
        int M=0, sum=0;
        for(pii i:V2){
            if(!(i.st&1) || i.nd==1)sum+=i.st;
            M=max(M, i.st);
        }
        int q;
        cin>>q;
        while(q--){
            ll x;
            cin>>x;
            if(x)cout<<max(sum, M)<<"\n";
            else cout<<M<<"\n";
        }
    }
}