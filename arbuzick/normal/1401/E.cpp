#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int R = 1 << 20;
int t[2][R*2];
int k = 0;
void build(){
    for(int i = 1; i < R*2; ++i)
        for(int j = 0; j < 2; ++j)
            t[j][i] = 0;
}
void change(int t1, int pos){
    pos += R;
    for(; pos > 0; pos /= 2)
        t[t1][pos]++;
}
int sum(int ql, int qr, int t1, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr)
        return t[t1][node];
    if(nr <= ql || qr <= nl)
        return 0;
    int nm = (nl+nr)/2;
    return sum(ql, qr, t1, node*2, nl, nm)+sum(ql, qr, t1, node*2+1, nm, nr);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    vector<pair<int, int>> g1, g2;
    vector<int> g3;
    for(int i = 0; i < n; ++i){
        int y, l, r;
        cin >> y >> l >> r;
        if(l == 0 && r == 1000000){
            ans++;
            g3.pb(y);
        }else if(l == 0){
            g1.pb({y, r});
        }else{
            g2.pb({y, l});
        }
    }
    sort(all(g1));
    sort(all(g2));
    sort(all(g3));
    vector<pair<int, int>> v1, v2;
    vector<int> v3;
    for(int i = 0; i < m; ++i){
        int x, l, r;
        cin >> x >> l >> r;
        if(l == 0 && r == 1000000){
            v3.pb(x);
        }else if(l == 0){
            v1.pb({r, x});
        }else{
            v2.pb({l, x});
        }
    }
    sort(all(v1));
    sort(rall(v2));
    sort(all(v3));
    build();
    int j1 = 0, j2 = 0, j3 = 0;
    for(int i = 0; i < v1.size(); ++i){
        while(j1 < g1.size() && g1[j1].f <= v1[i].f)
            change(0, g1[j1].s), j1++;
        while(j2 < g2.size() && g2[j2].f <= v1[i].f)
            change(1, g2[j2].s), j2++;
        while(j3 < g3.size() && g3[j3] <= v1[i].f)
            j3++, k++;
        int s = sum(v1[i].s, R, 0)+sum(0, v1[i].s+1, 1);
        ans = ans+s+k;
    }
    build();
    k = 0;
    reverse(all(g1));
    reverse(all(g2));
    reverse(all(g3));
    j1 = 0, j2 = 0, j3 = 0;
    for(int i = 0; i < v2.size(); ++i){
        while(j1 < g1.size() && g1[j1].f >= v2[i].f)
            change(0, g1[j1].s), j1++;
        while(j2 < g2.size() && g2[j2].f >= v2[i].f)
            change(1, g2[j2].s), j2++;
        while(j3 < g3.size() && g3[j3] >= v2[i].f)
            j3++, k++;
        int s = sum(v2[i].s, R, 0)+sum(0, v2[i].s+1, 1);
        ans = ans+s+k;
    }
    while(j1 < g1.size())
        change(0, g1[j1].s), j1++;
    while(j2 < g2.size())
        change(1, g2[j2].s), j2++;
    while(j3 < g3.size())
        j3++, k++;
    for(int i = 0; i < v3.size(); ++i){
        int s = sum(v3[i], R, 0)+sum(0, v3[i]+1, 1);
        ans = ans+s+k+1;
    }
    cout << ans;
    return 0;
}