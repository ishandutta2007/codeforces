#include <bits/stdc++.h>

using namespace std;

#define int long long

map < int, int > Lef;
map < int, int > Righ;
int mod = 998244353;

int st(int a, int b){
    if (b == 0) return 1;
    if (b % 2 == 0){
        int q = st(a, b / 2);
        return q * q % mod;
    }
    return a * st(a, b - 1) % mod;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (Lef.find(x) == Lef.end()) Lef[x] = i;
        Righ[x] = i;
    }
    vector < pair < int, int > > Q;
    for (auto key : Lef){
        Q.push_back({key.second, -1});
        Q.push_back({Righ[key.first], 1});
    }
    sort(Q.begin(), Q.end());
    int tt = 0, bal = 0;
    for (auto key : Q){
        if (key.second == -1) bal++;
        else bal--;
        if (bal == 0) tt++;
    }
    cout << st(2, tt - 1) << '\n';
    return 0;
}