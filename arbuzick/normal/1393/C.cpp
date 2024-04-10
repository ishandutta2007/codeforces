#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
vector<int> cnt;
bool check(int m){
    auto cnt2 = cnt;
    set<pair<int, int>> s;
    int n = cnt.size();
    for(int i = 0; i < n; ++i)
        s.insert({cnt2[i], i});
    vector<int> a(n, -1);
    for(int i = 0; i < n; ++i){
        if(a[i] != -1)
            s.insert({cnt2[a[i]], a[i]});
        if(s.empty())
            return 0;
        auto p = *s.rbegin();
        s.erase(p);
        if(p.first == 0)
            return 0;
        cnt2[p.second]--;
        if(i+m+1 < n)
            a[i+m+1] = p.second;
    }
    return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        cnt.assign(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> a[i], a[i]--, cnt[a[i]]++;
        int l = 0, r = n;
        while(l < r-1){
            int m = (l+r)/2;
            if(check(m))
                l = m;
            else
                r = m;
        }
        cout << l << '\n';
    }
    return 0;
}