#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    vector < int > xot;
    map < int, int > m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (m.find(a[i]) == m.end())
            m[a[i]] = 1;
        else
            m[a[i]] += 1;
    }
    set < pair < int, int > > s;
    for (auto key : m){
        s.insert({key.second, key.first});
    }
    int l = 0, r = n + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        int kol = 0;
        auto s1 = s;
        while (kol < k && (int)s1.size() > 0){
            auto p = (*s1.rbegin());
            s1.erase(p);
            kol += (p.first / m);
        }
        if (kol >= k)
            l = m;
        else
            r = m;
    }
    if (l == 0)
        return 0;
    for (int i = 0; i < k; ++i){
        auto p = (*s.rbegin());
        s.erase(p);
        if (p.first >= l){
            s.insert({p.first - l, p.second});
            cout << p.second << " ";
        }
        else{
            //s.erase(p);
            i--;
        }
    }
    return 0;
}