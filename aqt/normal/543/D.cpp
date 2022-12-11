#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;
int N;
vector<int> graph[200005];
long long dpcld[200005], dppar[200005];
int par[200005];
long long pre[200005], suf[200005];
int preptr[200005], sufptr[200005];

long long mult(long long a, long long b){
    return (a%MOD*b%MOD)%MOD;
}

long long power(long long b, long long e){
    if(b == 0){
        return 1;
    }
    if(!e){
        return 1;
    }
    long long res = power(b, e/2);
    res = mult(res, res);
    if(e%2){
        return mult(res, b);
    }
    else{
        return res;
    }
}

void dfs1(int n){
    dpcld[n] = 1;
    for(int e : graph[n]){
        if(e != par[n]){
            par[e] = n;
            dfs1(e);
            dpcld[n] = mult(dpcld[n], dpcld[e]+1);
        }
    }
    int last = 0;
    for(int e : graph[n]){
        if(e != par[n]){
            pre[e] = mult(pre[last], dpcld[e]+1);
            preptr[e] = last;
            last = e;
        }
    }
    last = N+1;
    for(int i = graph[n].size()-1; i>=0; i--){
        int e = graph[n][i];
        if(e != par[n]){
            suf[e] = mult(suf[last], dpcld[e]+1);
            sufptr[e] = last;
            last = e;
        }
    }
}

void dfs2(int n){
    dppar[n] = (mult(dppar[par[n]], mult(pre[preptr[n]], suf[sufptr[n]]))+1)%MOD;
    for(int e : graph[n]){
        if(e != par[n]){
            dfs2(e);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    sufptr[1] = N+1;
    pre[0] = 1;
    suf[N+1] = 1;
    dfs1(1);
    dfs2(1);
    for(int i = 1; i<=N; i++){
        cout << mult(dpcld[i], dppar[i]) << " ";
    }
}