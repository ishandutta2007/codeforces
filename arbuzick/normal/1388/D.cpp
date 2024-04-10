#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), k(n), used(n), p, k1(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        if(b[i] != -1)
            b[i]--, k[b[i]]++;
    }
    int ans = 0;
    queue<int> q;
    for(int i = 0; i < n; ++i)
        if(k[i] == 0)
            q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(a[v] >= 0){
            used[v] = 1;
            p.pb(v);
        }
        if(b[v] != -1){
            k[b[v]]--;
            a[b[v]] = max(a[b[v]], a[b[v]]+a[v]);
            if(k[b[v]] == 0)
                q.push(b[v]);
        }
    }
    for(int i = 0; i < n; ++i){
        ans += a[i];
        if(used[i] == 0 && b[i] != -1 && used[b[i]] == 0)
            k1[b[i]]++;
    }
    vector<int> p1;
    for(int i = 0; i < n; ++i)
        if(used[i] == 0 && k1[i] == 0)
            q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        p1.pb(v);
        if(b[v] != -1 && used[b[v]] == 0){
            k1[b[v]]--;
            if(k1[b[v]] == 0)
                q.push(b[v]);
        }
    }
    cout << ans << '\n';
    for(int i = 0; i < p.size(); ++i)
        cout << p[i]+1 << ' ';
    for(int i = p1.size()-1; p1.size() != 0 && i >= 0; --i)
        cout << p1[i]+1 << ' ';
    return 0;
}