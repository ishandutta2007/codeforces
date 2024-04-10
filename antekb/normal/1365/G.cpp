#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=(1<<20)+5, INF=2e9+5, mod=1e9+7, K=13;
vector< vi > V;
vector<int> akt, Q[K];
ll ans[K];
void gen(int najm){
    if(sz(akt)==6){V.pb(akt); return;}
    for(int i=najm; i<K; i++){
        akt.push_back(i);
        gen(i+1);
        akt.pop_back();
    }
}
int main(){
    gen(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j:V[i]){
            Q[j].pb(i);
        }
    }
    for(int i=0; i<K; i++){
        if(sz(Q[i])==0)continue;
        cout<<"? "<<sz(Q[i])<<" ";
        for(int j:Q[i]){
            cout<<j+1<<" ";
        }
        cout.flush();
        cin>>ans[i];
    }
    cout<<"! ";
    for(int i=0; i<n; i++){
        vi czy(K);
        for(int j:V[i]){
            czy[j]=1;
        }
        ll res=0;
        for(int j=0; j<K; j++){
            if(!czy[j]){
                res=(res|ans[j]);
            }
        }
        cout<<res<<" ";
    }
    cout.flush();
}