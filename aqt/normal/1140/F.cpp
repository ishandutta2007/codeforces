#include <bits/stdc++.h>

using namespace std;

int N, M = 300000;
map<int, int> mp[300005];
int par[600005];
long long sz1[600005], sz2[600005];
long long ans = 0;
vector<pair<pair<int, int>, pair<int, int>>> edge[1500000];

int getrt(int x){
    while(par[x] != x){
        x = par[x];
    }
    return x;
}

int unite(int x, int y){
    x = getrt(x), y = getrt(y);
    if(x == y){
        return 0;
    }
    if(sz1[x]+sz2[x] < sz1[y]+sz2[y]){
        swap(x, y);
    }
    ans -= sz1[y]*sz2[y]+sz1[x]*sz2[x];
    sz1[x] += sz1[y];
    sz2[x] += sz2[y];
    par[y] = x;
    ans += sz1[x]*sz2[x];
    return y;
}

void solve(int l, int r, int idx){
    stack<int> stk;
    int mid = l+r>>1;
    for(auto e : edge[idx]){
        //cout << l << " " << r << " " << e.second.first << " " << e.second.second << endl;
        if(l == e.second.first && r == e.second.second){
            int n = unite(e.first.first, e.first.second);
            if(n){
                stk.push(n);
            }
        }
        else if(e.second.second <= mid){
            edge[2*idx].push_back(e);
        }
        else if(e.second.first > mid){
            edge[2*idx+1].push_back(e);
        }
        else{
            edge[2*idx].push_back({{e.first.first, e.first.second}, {e.second.first, mid}});
            edge[2*idx+1].push_back({{e.first.first, e.first.second}, {mid+1, e.second.second}});
        }
    }
    if(l == r){
        cout << ans << " ";
    }
    else{
        solve(l, mid, 2*idx);
        solve(mid+1, r, 2*idx+1);
    }
    while(stk.size()){
        int n = stk.top();
        stk.pop();
        int rt = getrt(n);
        ans -= sz1[rt]*sz2[rt];
        sz1[rt] -= sz1[n];
        sz2[rt] -= sz2[n];
        par[n] = n;
        ans += sz1[rt]*sz2[rt] + sz1[n]*sz2[n];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=2*M; i++){
        par[i] = i;
        if(i > M){
            sz2[i] = 1;
        }
        else{
            sz1[i] = 1;
        }
    }
    for(int i = 1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        y += M;
        if(mp[x][y]){
            edge[1].push_back({{x, y}, {mp[x][y], i-1}});
            mp[x][y] = 0;
        }
        else{
            mp[x][y] = i;
        }
    }
    for(int i = 1; i<=M; i++){
        for(auto p : mp[i]){
            if(p.second){
                edge[1].push_back({{i, p.first}, {p.second, N}});
            }
        }
    }
    solve(1, N ,1);
}