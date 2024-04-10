#include <bits/stdc++.h>

using namespace std;

vector < int > a;
bool check(int x){
    multiset < int > Q;
    for (int i = x; i < (int)a.size() - x; ++i) Q.insert(a[i]);
    for (int i = 0; i < x; ++i){
        int l = a[i], r = a[(int)a.size() - x + i];
        auto it = Q.upper_bound(l);
        if (it == Q.end()) return false;
        if ((*it) >= r) return false;
        Q.erase(it);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int l = 0, r = n / 3 + 1;
    while (r - l > 1){
        int m = (r + l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
    x = l;
    multiset < int > Q;
    for (int i = x; i < (int)a.size() - x; ++i) Q.insert(a[i]);
    for (int i = 0; i < x; ++i){
        int l = a[i], r = a[(int)a.size() - x + i];
        auto it = Q.upper_bound(l);
        cout << r << " " << (*it) << " " << l << '\n';
        Q.erase(it);
    }
    return 0;
}