#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 1e+6 + 5;

ll a[N],ct[N];
ll n,m,h,x,u,v;
vector <ll> adj[N];
string s;
stack <ll> st;

int main(){
    cin>>n>>h>>m;
    for(int i=0; i<h; i++){
        cin>>x;
        a[x] = 1;
    }
    x = 1;
    for(int i = 0; i<m; i++){
        if(a[x] == 1) break;
        cin>>u>>v;
        if(u == x) x = v;
        else if(v == x) x = u;
    }
    cout<<x<<endl;
}