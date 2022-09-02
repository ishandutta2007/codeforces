#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

int p = 1000000007;


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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

void solve()
{
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for (int i = 1; i<=n; i++) cin>>a[i];

    ll sum = 0;
    for (auto it: a) sum+=it;
    if (sum%n) {cout<<-1<<endl; return;}
    ll need = sum/n;

    vector<pair<pair<int, int>, int>> ops;

    for (int i = 2; i<=n; i++) if (a[i])
    {
        int to_do;
        if (a[i]%i) to_do = i - a[i]%i; else to_do = 0;
        if (to_do)
        {
            ops.push_back(mp(mp(1, i), to_do));
            a[1]-=to_do;
            a[i]+=to_do;
        }

        int cnt = a[i]/i;
        ops.push_back(mp(mp(i, 1), cnt));
        a[1]+=a[i]; a[i] = 0;
    }

    for (int i = 2; i<=n; i++) ops.push_back(mp(mp(1, i), need));
    cout<<ops.size()<<endl;
    for (auto it: ops) cout<<it.first.first<<' '<<it.first.second<<' '<<it.second<<endl;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();


}