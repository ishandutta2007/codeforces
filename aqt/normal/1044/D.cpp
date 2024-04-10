#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[400005];
int idx;
map<int, int> mp;
int Q;
int par[400005];
int sz[400005];
int dist[400005];

void dfs(int n, int p){
    for(auto e : graph[n]){
        if(e.first != p){
            dist[e.first] = dist[n] ^ e.second;
            dfs(e.first, n);
        }
    }
}

int getidx(int n){
    if(!mp.count(n)){
        mp[n] = ++idx;
        par[idx] = idx;
        sz[idx] = 1;
    }
    return mp[n];
}

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> Q;
    int lst = 0;
    while(Q--){
        int c, l, r;
        cin >> c >> l >> r;
        l ^= lst, r ^= lst;
        //cout << l << " " << r << "\n";
        if(l > r){
            swap(l, r);
        }
        r++;
        if(c == 1){
            l = getidx(l), r = getidx(r);
            int v;
            cin >> v;
            v ^= lst;
            if(getrt(l) != getrt(r)){
                graph[l].push_back({r, v});
                graph[r].push_back({l, v});
                if(sz[getrt(l)] < sz[getrt(r)]){
                    swap(l, r);
                }
                sz[getrt(l)] += sz[getrt(r)];
                par[getrt(r)] = getrt(l);
                dist[r] = dist[l] ^ v;
                dfs(r, l);
            }
        }
        else{
            if(mp.count(l) && mp.count(r)){
                l = getidx(l), r = getidx(r);
                if(getrt(l) == getrt(r)){
                    cout << (lst = dist[l] ^ dist[r]) << "\n";
                }
                else{
                    cout << -1 << "\n";
                    lst = 1;
                }
            }
            else{
                cout << -1 << "\n";
                lst = 1;
            }
        }
    }
}