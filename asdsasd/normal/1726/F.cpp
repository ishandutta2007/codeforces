#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/lazysegtree>
using namespace std;
// using namespace atcoder;
const long long inf = 1LL << 60;

void solve(){
    int n;
    long long T;
    cin >> n >> T;
    vector<long long> G(n), C(n);
    for(int i = 0; i < n; i++) cin >> G[i] >> C[i];
    vector<long long> D(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> D[i];

    set<vector<long long>> se;
    se.insert({-inf, -inf, inf});
    se.insert({-inf-1, -inf, inf});
    se.insert({0, T - 1, 0});
    se.insert({inf, inf, inf});
    long long t = 0;
    for(int i = 0; i < n; i++){
        long long g = G[i];
        long long c = C[i];
        long long st = (g - t - c) % T;
        long long tt = (-t - c) % T;
        if(st < 0) st += T;
        if(tt < 0) tt += T;

        if(st < tt){
            auto it = se.lower_bound({st, st, 0});
            it--;
            it--;
            while((*it)[1] < st) it++;
            long long mi = inf;
            while(1){
                auto tmp = (*it);
                if (tmp[1] < tt){
                    mi = min(mi, tmp[2] + tt - tmp[1]);
                    se.erase(it++);
                    if(tmp[0] < st){
                        tmp[1] = st - 1;
                        se.insert(tmp);
                    }
                }
                else if(tmp[0] > tt){
                    if(mi != inf) se.insert({tt, tt, mi});
                    break;
                }
                else{                    
                    mi = min(mi, tmp[2]);
                    auto tmp2 = (*it);
                    se.erase(it);
                    if(tmp[0] < st){
                        tmp[1] = st - 1;
                        se.insert(tmp);
                    }
                    if(tmp2[1] > tt){
                        tmp2[0] = tt + 1;
                        se.insert(tmp2);
                    }
                    if(mi != inf) se.insert({tt, tt, mi});
                    break;
                }
            }
        }
        else{
            auto it = se.lower_bound({st, st, 0});
            it--;
            it--;
            while((*it)[1] < st) it++;
            long long mi = inf;
            while(1){
                auto tmp = (*it);
                if (tmp[1] < T){
                    mi = min(mi, tmp[2] + tt + (T - tmp[1]));
                    se.erase(it++);
                    if(tmp[0] < st){
                        tmp[1] = st - 1;
                        se.insert(tmp);
                    }
                }
                else if(tmp[0] > T){
                    if(mi != inf) se.insert({tt, tt, mi});
                    break;
                }
                else{
                    mi = min(mi, tmp[2]);
                    auto tmp2 = (*it);
                    se.erase(it);
                    if(tmp[0] < st){
                        tmp[1] = st - 1;
                        se.insert(tmp);
                    }
                    break;
                }
            }

            it = se.lower_bound({0, 0, 0});
            it--;
            it--;
            while((*it)[1] < 0) it++;
            while(1){
                auto tmp = (*it);
                if (tmp[1] < tt){
                    mi = min(mi, tmp[2] + tt - tmp[1]);
                    se.erase(it++);
                }
                else if(tmp[0] > tt){
                    if(mi != inf) se.insert({tt, tt, mi});
                    break;
                }
                else{
                    mi = min(mi, tmp[2]);
                    auto tmp2 = (*it);
                    se.erase(it);
                    if(tmp2[1] > tt){
                        tmp2[0] = tt + 1;
                        se.insert(tmp2);
                    }
                    if(mi != inf) se.insert({tt, tt, mi});
                    break;
                }
            }

        }

        if(i != n - 1) t += D[i];
    }

    long long ans = inf;
    for(auto tmp:se){
        ans = min(ans, tmp[2]);
    }
    ans += t;
    cout << ans << "\n";
    
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}