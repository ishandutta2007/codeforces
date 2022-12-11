#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
int dep[200005], sz[200005], par[200005];

void dfs1(int n, int p){
    for(int e : graph[n]){
        if(e != p){
            par[e] = n;
            dep[e] = dep[n] + 1;
            dfs1(e, n);
        }
    }
}

void dfs2(int n, int p, int d){
    if(dep[n] == d){
        sz[n] = 1;
        graph[n].clear();
        return;
    }
    for(int e : graph[n]){
        if(e != p){
            dfs2(e, n, d);
            sz[n] += sz[e];
        }
    }
}

int getcent(int n, int t){
    int hvy = 0;
    for(int e : graph[n]){
        if(dep[e] > dep[n]){
            hvy = (sz[hvy] >= sz[e] ? hvy : e);
        }
    }
    if(sz[hvy]*2 > sz[t]){
        return getcent(hvy, t);
    }
    else{
        return n;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1, 0);
    cout << "d " << 1 << endl;
    int D;
    cin >> D;
    if(D == 0){
        cout << "! " << 1 << endl;
        return 0;
    }
    dfs2(1, 0, D);
    int lst = 1;
    int T = 18;
    while(T--){
        int C = getcent(lst, lst);
        cout << "d " << C << endl;
        int d;
        cin >> d;
        if(d == 0){
            cout << "! " << C << endl;
            return 0;
        }
        if(D - dep[C] == d){
            cout << "s " << C << endl;
            cin >> lst;
        }
        else{
            int n = C;
            while((dep[C] + D-d)/2 != dep[n]){
                n = par[n];
            }
            cout << "s " << n << endl;
            cin >> lst;
        }
    }
}