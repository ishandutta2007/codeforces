#include <bits/stdc++.h>

using namespace std;

int N;
int par[1000005], sz[1000005];
vector<pair<int, int>> v;
bool tkn[1000005];
vector<int> graph[1000005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

long long calc(){
    for(int i = 1; i<=N; i++){
        par[i] = i;
        tkn[i] = 0;
        sz[i] = 1;
    }
    long long ret = 0;
    for(auto p : v){
        tkn[p.second] = 1;
        for(int e : graph[p.second]){
            if(tkn[e]){
                ret += 1LL*p.first*sz[p.second]*sz[getrt(e)];
                sz[p.second] += sz[getrt(e)];
                par[getrt(e)] = p.second;
            }
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back({n, i});
    }
    sort(v.begin(), v.end());
    for(int i= 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long ans = calc();
    reverse(v.begin(), v.end());
    ans -= calc();
    cout << ans << endl;
}