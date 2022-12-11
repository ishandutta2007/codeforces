#include <bits/stdc++.h>

using namespace std;

int N, tar, rt;
vector<int> graph[1000005];
int val[1000005];
int cut[1000005];
int sum[1000005];
int par[1000005];

void dfs(int n){
    sum[n] = val[n];
    for(int e : graph[n]){
        if(par[n] != e){
            par[e] = n;
            dfs(e);
            sum[n] += sum[e];
            if(cut[n]){
                if(cut[e]){
                    cout << cut[n] << " " << cut[e] << endl;
                    exit(0);
                }
            }
            else{
                cut[n] = cut[e];
            }
        }
    }
    if(sum[n] == tar){
        cut[n] = n;
    }
    else if(sum[n] == 2*tar && cut[n]){
        cout << n << " " << cut[n] << endl;
        exit(0);
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        int p;
        scanf("%d %d", &p, &val[i]);
        tar += val[i];
        if(p){
            graph[p].push_back(i);
            graph[i].push_back(p);
        }
        else{
            rt = i;
        }
    }
    if(tar%3){
        cout << -1 << endl;
        return 0;
    }
    tar /= 3;
    dfs(rt);
    cout << -1 << endl;
}