#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

vector<long long> divs(long long a){
    vector<long long> ret;
    for(int i = 1; i * i <= a; i++){
        if(a % i == 0){
            ret.push_back(i);
            if(i * i != a) ret.push_back(a / i);
        }
    }
    return ret;
}

void solve(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    auto d1 = divs(a);
    auto d2 = divs(b);
    for(auto da:d1){
        for(auto db:d2){
            long long dd = da * db;
            long long xx = a * b / dd;
            dd = c / dd * dd;
            if(dd <= a) continue;
            else if(dd > c) break;
            if(d / xx * xx > b){
                cout << dd << " " << d / xx * xx << "\n";
                return;
            }
        }
    }
    cout << "-1 -1" << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}