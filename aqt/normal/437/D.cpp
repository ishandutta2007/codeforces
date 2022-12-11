#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
vector<pair<double,int>> v;
int par[100005], sz[100005];
bool tkn[100005];

int getrt(int n){
    return par[n] = (n == par[n] ? n : getrt(par[n]));
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        par[i] = i;
        sz[i] = 1;
        double n;
        cin >> n;
        v.push_back({n, i});
    }
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    double ans = 0;
    for(auto p : v){
        tkn[p.second] = 1;
        for(int e : graph[p.second]){
            if(tkn[e]){
                int k = getrt(e);
                if(k == p.second){
                    continue;
                }
                ans += p.first*sz[k]*sz[p.second];
                par[k] = p.second;
                sz[p.second] += sz[k];
            }
        }
    }
    cout << ans*2.0/((1.0*N)*(N-1)) << endl;
}