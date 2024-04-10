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

const int N=2e5+5, INF=1e9+5, mod=1e9+7, K=100;
int encode(char c1, char c2){return (c1-'0')*K+c2-'0';}
pair<char, char> decode(int k){return mp((k/K)+'0',(k%K)+'0');}
int czy[N], in[N], out[N];
vi E[K*K];
vi V;
bool check(){
    int k=0;
    for(int i=0; i<K*K; i++){
        if(abs(in[i]-out[i]))k++;
        if(abs(in[i]-out[i])>1)return 0;
    }
    return k<=2;
}
void go(int v){
    while(sz(E[v])){
        auto e=E[v].back();
        E[v].pp();
        out[v]--;
        in[e]--;
        go(e);
    }
    V.pb(v);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        str t;
        cin>>t;
        int a=encode(t[0], t[1]);
        int b=encode(t[1], t[2]);
        E[a].pb(b);
        out[a]++;
        in[b]++;
        //E[b].pb(mp(a, i));
    }
    if(!check()){cout<<"NO";return 0;}
    bool b=1;
    for(int i=0; i<K*K; i++){
        if(in[i]<out[i]){
            go(i);
            b=0;
            break;
        }
    }
    if(b)for(int i=0; i<K*K; i++)if(sz(E[i])){go(i);break;}
    for(int i=0; i<K*K; i++)if(sz(E[i])){cout<<"NO";return 0;}
    cout<<"YES\n";
    rev(V);
    vector<char> V2;
    V2.pb(decode(V[0]).st);
    for(int i:V){
        V2.pb(decode(i).nd);
    }
    for(char c:V2)cout<<c;
}