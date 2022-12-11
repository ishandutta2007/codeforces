#include <bits/stdc++.h>

using namespace std;

int N, rt;
vector<int> graph[200005];
vector<int> ans;
int sz[200005];

void dfs1(int n, int p){
    sz[n] = 1;
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        dfs1(e, n);
        sz[n] += sz[e];
    }
}

void dfs2(int n, int p){
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        if(sz[e]%2 == 0){
            dfs2(e, n);
        }
    }
    ans.push_back(n);
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        if(sz[e]%2){
            dfs2(e, n);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        int p;
        cin >> p;
        if(!p){
            continue;
        }
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    for(int i = 1;i <=N; i++){
        if(graph[i].size()%2 == 0){
            rt = i;
        }
    }
    dfs1(rt, 0);
    if(N%2 == 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << "\n";
        dfs2(rt, 0);
        for(int n : ans){
            cout << n << "\n";
        }
    }
}