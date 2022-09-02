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
{*
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, h, m, k;
    cin>>n>>h>>m>>k;

    /*if (k == m/2)
    {
        cout<<n<<' '<<0<<endl;
        for (int i = 0; i<n; i++) cout<<i+1<<' ';
        return 0;
    }*/

    vector<pair<ll, ll>> a(n);

    vector<pair<ll, ll>> bounds;

    ll period = m/2;

    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first>>a[i].second;
        ll st = a[i].first * m + a[i].second + k;
        st%=period;
        bounds.push_back(mp(st, st + period - k));
        bounds.push_back(mp(st + period, st + 2*period - k));
    }

    map<ll, int> starts, ends;
    for (auto it: bounds)
    {
        starts[it.first]++;
        ends[it.second]++;
    }

    ll best = -1;
    ll val = -1;

    ll cur = 0;

    set<ll> guys;
    for (auto it: bounds)
    {
        guys.insert(it.first);
        guys.insert(it.second);
    }

    for (auto it: guys)
    {
        cur+=starts[it];
        if (cur>val) {val = cur; best = it;}
        cur-=ends[it];
    }

    best%=period;

    vector<int> reject;
    for (int i = 0; i<n; i++)
    {
        ll st = a[i].first * m + a[i].second + 1;
        st%=period;
        ll en = st + k-2;
        if (st<=best && best<=en) reject.push_back(i);
        else if (st<=best+period && best+period<=en) reject.push_back(i);
    }

    cout<<reject.size()<<' '<<best<<endl;
    for (auto it: reject) cout<<it+1<<' ';







}