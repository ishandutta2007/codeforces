#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2e5+5, INF=1e9+5;
int tab[N];
vi tab2[N];
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vi V;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        V.push_back(x);
    }
    for(int i=1; i<=k; i++){
        cin>>tab[i];
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, (i+tab[V[i]])/tab[V[i]]);
    }
    cout<<ans<<"\n";
    set<pii> S;
    for(int i=0; i<ans; i++){
        S.insert({0, i});
    }
    for(int i:V){
        auto it=S.begin();
        pii x=(*it);
        tab2[x.nd].push_back(i);
        S.erase(it);
        x.st++;
        S.insert(x);
    }
    for(int i=0; i<ans; i++){
        cout<<tab2[i].size()<<" ";
        for(int j:tab2[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}