#include <bits/stdc++.h>
using namespace std;

const int N=3e5+5;
typedef long long ll;
typedef pair<int, int> ii;

int n, w[N];
vector <ii> nebo[N];
ll res, f[N];

void init(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> w[i];
    }
    for (int i=0; i<n-1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        nebo[u].push_back(make_pair(v,c));
        nebo[v].push_back(make_pair(u,c));
    }
    res=0;
}

void visit(int v, int u){
    ll max1=0;
    ll max2=0;
    for (int i=0; i<nebo[v].size(); i++){
        ii t=nebo[v][i];
        int next=t.first;
        int weight=t.second;
        if (next==u) continue;
        visit(next, v);
        if (f[next]-weight>max1){
            max2=max1;
            max1=f[next]-weight;
        } else if (f[next]-weight>max2){
            max2=f[next]-weight;
        }
    }
    f[v]=w[v]+max1;
    res=max(res, f[v]+max2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    visit(1, 0);
    cout << res;
}