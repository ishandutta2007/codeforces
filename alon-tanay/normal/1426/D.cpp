#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> as(n);
    map<ll,int> lst;
    lst[0] = 0;
    for(ll &x : as) {
        cin >> x;
    }
    vector<ll> pre(n+1);
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i-1] + as[i-1];
    }
    vector<pi> segs;
    for(int i = 1; i <= n; i ++) {
        if(lst.find(pre[i])!=lst.end()) {
            segs.push_back({lst[pre[i]]+1,i-1});
        }
        lst[pre[i]] = i;
    }
    sort(segs.begin(),segs.end());
    int bl = 1e9;
    int cnt = 0;
    for(int i = segs.size()-1; i >= 0; i --) {
        if(segs[i].s >= bl) { continue; }
        cnt ++;
        bl = segs[i].f;
    }
    cout << cnt;
    return 0;
}