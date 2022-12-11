#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
vector<int> temp[100005];
long long tot[100005], sub[100005], sz[100005];
int par[100005][17], lft[100005], rht[100005], t = 0, dep[100005];

void dfs1(int n){
    sz[n] = 1;
    lft[n] = ++t;
    for(int e : graph[n]){
        if(e != par[n][0]){
            par[e][0] = n;
            dep[e] = dep[n] + 1;
            temp[n].push_back(e);
            dfs1(e);
            sz[n] += sz[e];
            sub[n] += sz[e] + sub[e];
        }
    }
    rht[n] = ++t;
}

void dfs2(int n){
    tot[n] += sub[n];
    for(int e : graph[n]){
        if(e != par[n][0]){
            tot[e] = tot[n] + N - sub[e] - 2*sz[e];
            dfs2(e);
        }
    }
}

int lca(int a, int b){
    if(dep[a] < dep[b]){
        swap(a, b);
    }
    for(int i = 16; i>=0; i--){
        if(dep[par[a][i]] >= dep[b]){
            a = par[a][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = 16; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1);
    for(int i= 1; i<=N; i++){
        graph[i] = temp[i];
    }
    dfs2(1);
    /*
    for(int i = 1; i<=N; i++){
        cout << "dfs range: " << i << " " << lft[i] << " " << rht[i] << endl;
        cout << "tot: " << i << " " << tot[i] << endl;
        cout << "sz: " << i << " " << sz[i] << endl;
        cout << "sub: " << i << " " << sub[i] << endl;
    }
    */
    for(int d = 1; d<=16; d++){
        for(int i = 1; i<=N; i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
    while(M--){
        int a, b;
        scanf("%d %d", &a, &b);
        double ans = 1 + dep[a] + dep[b] - 2*dep[lca(a,b)];
        if(rht[a] < lft[b] || rht[b] < lft[a]){
            ans += (sz[a]*sub[b]+sz[b]*sub[a])/(1.0*sz[a]*sz[b]);
        }
        else{
            if(rht[a]-lft[a] < rht[b]-lft[b]){
                swap(a, b);
            }
            int l = 0, r = graph[a].size()-1, c = 0;
            while(l <= r){
                int mid = (l+r)>>1;
                if(lft[graph[a][mid]] <= lft[b]){
                    c = graph[a][mid];
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            ans += (sz[b]*(tot[a]-sub[c]-sz[c])+(N-sz[c])*sub[b])/(1.0*(N-sz[c])*sz[b]);
        }
        printf("%.10f\n", ans);
    }
}