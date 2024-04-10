#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, pair<int, int>> edge[200005];
int par[200005];
bool cycle[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        par[i] = i;
    }
    for(int i = 1; i<=M; i++){
        int a, b, v;
        cin >> a >> b >> v;
        edge[i] = {v, {a, b}};
    }
    sort(edge+1, edge+1+M, greater<pair<int, pair<int, int>>>());
    long long ans = 0;
    for(int i = 1; i<=M; i++){
        int a = edge[i].second.first, b = edge[i].second.second, v = edge[i].first;
        int ap = getrt(a), bp = getrt(b);
        if(ap == bp){
            if(!cycle[ap]){
                cycle[ap] = 1;
                ans += v;
            }
        }
        else{
            if(cycle[ap] && cycle[bp]){
                continue;
            }
            ans += v;
            par[ap] = bp;
            cycle[bp] |= cycle[ap];
        }
    }
    cout << ans << endl;
}