#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int d, n, m;
    cin>>n>>d>>m;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<ll> pref(n+1);
    for (int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;
    for (auto it: pref) cout<<it<<' ';
    cout<<endl;*/

    int st = 0;
    while (st<n && a[st]>m) st++;

    ll maxx = 0;
    for (int cnt = 0; cnt<n; cnt++)
    {
        int take_small = cnt;
        int take_big = (n - cnt + d)/(d+1);
        ll cur = pref[take_big];
        int st1 = max(st, take_big);
        take_small = min(take_small, n-st1);
        cur+=(pref[st1 + take_small] - pref[st1]);
        maxx = max(maxx, cur);
    }
    cout<<maxx;




}