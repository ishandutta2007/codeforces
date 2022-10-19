#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/dsu>
using namespace std;
//using namespace atcoder;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<pair<long long, long long>, int>> lr(n);
    vector<int> cnt(n);
    vector<long long> size(n);
    for(int i = 0; i < n; i++){
        cin >> lr[i].first.first >> size[i];
        lr[i].first.second = lr[i].first.first + size[i];
        lr[i].second = i;
    }
    set<pair<pair<long long, long long>, int>> se;
    sort(lr.begin(), lr.end());
    se.insert({{-1, -1}, -1});
    for(auto tmp:lr){
        auto it = se.end();
        it--;
        if(tmp.first.second <= (*it).first.second) continue;
        if(tmp.first.first <= (*it).first.second) tmp.first.first = (*it).first.second + 1;
        se.insert(tmp);
    }
    se.insert({{1LL << 60, 1LL << 60}, -1});
    multiset<pair<long long, long long>> mos;
    mos.insert({-1, -1});
    mos.insert({1LL << 60, -1});
    long long p, b;
    for(int i = 0; i < m; i++){
        cin >> p >> b;
        auto it = se.lower_bound({{p, p}, -1});
        it--;
        while((*it).first.second < p) it++;
        if((*it).first.first <= p && p <= (*it).first.second){
            auto tmp = *it;
            se.erase(it++);
            cnt[tmp.second]++;
            size[tmp.second] += b;
            tmp.first.second += b;
            auto it2 = mos.lower_bound({tmp.first.first, -1});
            while(tmp.first.second >= (*it2).first){
                cnt[tmp.second]++;
                size[tmp.second] += (*it2).second;
                tmp.first.second += (*it2).second;
                mos.erase(it2++);
            }
            while((*it).first.first <= tmp.first.second){
                if((*it).first.second <= tmp.first.second){
                    se.erase(it++);
                }
                else{
                    auto tmp2 = *it;
                    se.erase(it);
                    tmp2.first.first = tmp.first.second + 1;
                    se.insert(tmp2);
                    break;
                }
            }
            se.insert(tmp);
        }
        else{
            mos.insert({p, b});
        }
    }
    for(int i = 0; i < n; i++){
        cout << cnt[i] << " " << size[i] << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
}