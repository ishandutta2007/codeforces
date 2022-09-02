#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) cin>>b[i];
    for (int i = 0; i<n; i++) cin>>c[i];
    vector<int> ans = {a[0]};
    for (int i = 1; i<n-1; i++)
    {
        if (a[i]!=ans.back()) ans.push_back(a[i]); else ans.push_back(b[i]);
    }

    if (a[n-1]!=ans.back() && a[n-1]!=ans[0]) ans.push_back(a[n-1]);
    else if (b[n-1]!=ans.back() && b[n-1]!=ans[0]) ans.push_back(b[n-1]);
    else ans.push_back(c[n-1]);
    for (auto it: ans) cout<<it<<' ';
    cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();


}