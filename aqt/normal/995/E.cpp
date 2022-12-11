#include <bits/stdc++.h>

using namespace std;

long long u, v;
long long MOD;
map<long long, int> par, clr, lst;
queue<long long> qu;

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = ret*ret %MOD;
    if(e&1){
        ret = ret*b;
        ret %= MOD;
    }
    return ret;
}

int main(){
    cin >> u >> v >> MOD;
    par[u] = 0, par[v] = 0;
    clr[u] = 1, clr[v] = 2;
    qu.push(u), qu.push(v);
    if(u == v){
        cout << 2 << "\n" << 1 << " " << 2 << endl;
        return 0;
    }
    while(qu.size()){
        long long n = qu.front();
        qu.pop();
        vector<long long> vec = {(n+1)%MOD, (n+MOD-1)%MOD, qikpow(n, MOD-2)};
        for(int i = 0; i<3; i++){
            long long e = vec[i];
            if(clr.count(e)){
                if(clr[e] != clr[n]){
                    vector<pair<long long, long long>> ans;
                    long long t = i+1LL;
                    if(clr[n] == 2){
                        swap(e, n);
                        if(t <= 2){
                            t = 3-t;
                        }
                    }
                    while(n != u){
                        ans.push_back({par[n], lst[n]});
                        n = par[n];
                    }
                    reverse(ans.begin(), ans.end());
                    ans.push_back({0LL, t});
                    n = e;
                    while(n != v){
                        if(lst[n] <= 2){
                            lst[n] = 3-lst[n];
                        }
                        ans.push_back({n, lst[n]});
                        n = par[n];
                    }
                    cout << ans.size() << "\n";
                    for(auto p : ans){
                        cout << p.second << " ";
                    }
                    return 0;
                }
            }
            else{
                clr[e] = clr[n];
                par[e] = n;
                lst[e] = i+1;
                qu.push(e);
            }
        }
    }
}