#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=3e5+5;
const ll INF=1e9+5;
int lst[3][N], nxt[3][N];
ll ask(ll a, ll b, ll c){
    //cout<<a<<" "<<b<<" "<<c<<"\n";
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int nr, ng, nb;
        cin>>nr>>ng>>nb;
        vector<pii> V;
        V.push_back({-INF, -1});
        for(int i=0; i<nr; i++){
            int x;
            cin>>x;
            V.push_back({x, 0});
        }
        for(int i=0; i<ng; i++){
            int x;
            cin>>x;
            V.push_back({x, 1});
        }
        for(int i=0; i<nb; i++){
            int x;
            cin>>x;
            V.push_back({x, 2});
        }

        sort(V.begin(), V.end());
        lst[0][0]=-INF;
        lst[1][0]=-INF;
        lst[2][0]=-INF;
        for(int i=1; i<V.size(); i++){
            lst[0][i]=lst[0][i-1];
            lst[1][i]=lst[1][i-1];
            lst[2][i]=lst[2][i-1];
            lst[V[i].nd][i]=V[i].st;
        }

        nxt[0][V.size()]=INF;
        nxt[1][V.size()]=INF;
        nxt[2][V.size()]=INF;
        for(int i=V.size()-1; i>0; i--){
            nxt[0][i]=nxt[0][i+1];
            nxt[1][i]=nxt[1][i+1];
            nxt[2][i]=nxt[2][i+1];
            nxt[V[i].nd][i]=V[i].st;
        }
        //cout<<"a";
        ll ans=2*INF*INF;
        for(int i=2; i<V.size()-1; i++){
            //cout<<"b"<<V[i].st<<" "<<V[i].nd<<"b";
            //cout<<lst[0][i]<<" "<<lst[1][i]<<" "<<lst[2][i]<<" ";
            if(nxt[(V[i].nd+1)%3][i]!=INF && lst[(V[i].nd+2)%3][i]!=-INF) ans=min(ans, ask(V[i].st, nxt[(V[i].nd+1)%3][i], lst[(V[i].nd+2)%3][i]));
            //cout<<"c";
            if(nxt[(V[i].nd+2)%3][i]!=INF && lst[(V[i].nd+1)%3][i]!=-INF) ans=min(ans, ask(V[i].st, nxt[(V[i].nd+2)%3][i], lst[(V[i].nd+1)%3][i]));
        }
        cout<<ans<<"\n";
    }
}