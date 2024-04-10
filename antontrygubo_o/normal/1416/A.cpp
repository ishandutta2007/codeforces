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
    vector<int> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}

    vector<vector<int>> pos(n);
    for (int i = 0; i<n; i++)
    {
        pos[i].push_back(-1);
    }
    for (int i = 0; i<n; i++) pos[a[i]].push_back(i);
    for (int i = 0; i<n; i++)
    {
        pos[i].push_back(n);
    }

    vector<pair<int, int>> b;
    for (int i = 0; i<n; i++)
    {
        int res = 0;
        for (int j = 0; j+1<pos[i].size(); j++) res = max(res, pos[i][j+1] - pos[i][j]);
        b.push_back(mp(res, i));
    }

    sort(b.begin(), b.end());
    /*for (auto it: b) cout<<it.first<<' '<<it.second<<endl;
    cout<<endl;*/

    int minn = 1e9;

    int cur = 0;
    for (int i = 1; i<=n; i++)
    {
        while (cur<n && b[cur].first<=i) {minn = min(minn, b[cur].second); cur++;}
        if (minn == 1e9) cout<<-1<<' ';
        else cout<<minn+1<<' ';
    }
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