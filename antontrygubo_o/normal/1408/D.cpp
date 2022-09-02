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

pair<int, int> need(pair<int, int> a, pair<int, int> b)
{
    return mp(max(0, b.first - a.first + 1), max(0, b.second - a.second + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> rob(n), proj(m);
    for (auto &it: rob) cin>>it.first>>it.second;
    for (auto &it: proj) cin>>it.first>>it.second;

    vector<pair<int, int>> bruh(n*m);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) bruh[i*m + j] = need(rob[i], proj[j]);

    sort(bruh.begin(), bruh.end());
    int ans = bruh[n*m-1].first;
    int curmax = bruh[n*m-1].second;
    for (int i = n*m-2; i>=0; i--)
    {
        ans = min(ans, bruh[i].first + curmax);
        curmax = max(curmax, bruh[i].second);
    }
    ans = min(ans, curmax);
    cout<<ans<<endl;
}
/*
1
 5 3
1 2 3 4 5
 */