#include <bits/stdc++.h>

using namespace std;

int n;
vector < pair < int, int > > a;

void ans(){
    cout << "Yes" << '\n';
    exit(0);
}

bool check(int k){
    if (k == n) return false;
    for (auto key : a){
        int x = (key.first + k) % n, y = (key.second + k) % n;
        if (x == 0) x = n;
        if (y == 0) y = n;
        if (x > y) swap(x, y);
        pair < int, int > tmp = {x, y};
        int it = lower_bound(a.begin(), a.end(), tmp) - a.begin();
        if (it == (int)a.size() || a[it] != tmp) return false;
    }
    return true;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> x >> y;
        if (x > y) swap(x, y);
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i * i <= n; ++i){
        if (check(i)) ans();
        if (check(n / i)) ans();
    }
    cout << "No" << '\n';
    return 0;
}