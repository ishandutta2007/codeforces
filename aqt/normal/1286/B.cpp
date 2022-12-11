#include <bits/stdc++.h>

using namespace std;

int N;
int ans[2005];
int val[2005];
int rt;
int sz[2005];
vector<int> graph[2005];

void dfs3(int n, int v){
    if(ans[n] >= v){
        ans[n]++;
    }
    for(int e : graph[n]){
        dfs3(e, v);
    }
}

void dfs2(int n, int v){
    ans[n] += v;
    for(int e : graph[n]){
        dfs2(e, v);
    }
}

void dfs1(int n){
    for(int e : graph[n]){
        dfs1(e);
        dfs2(e, sz[n]);
        sz[n] += sz[e];
    }
    sz[n]++;
    if(sz[n] < val[n]){
        cout << "NO" << endl;
        exit(0);
    }
    ans[n] = val[n];
    for(int e : graph[n]){
        dfs3(e, val[n]);
    }
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        int p;
        cin>> p >> val[i];
        val[i]++;
        if(!p){
            rt = i;
        }
        else{
            graph[p].push_back(i);
        }
    }
    dfs1(rt);
    cout << "YES\n";
    for(int i = 1; i<=N; i++){
        cout<< ans[i] << " ";
    }
}