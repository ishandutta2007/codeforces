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


int inv3 = inv(3);

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans = 0;

    map<char, vector<int>> pref, suf;
    for (auto c : {'a', 'c', '?'})
    {
        pref[c] = vector<int>(n+1);
        suf[c] = vector<int>(n+1);
    }

    for (int i = 0; i<n; i++)
    {
        for (auto c : {'a', 'c', '?'})
        {
            pref[c][i+1] = pref[c][i];
            if (c==s[i]) pref[c][i+1]++;
        }
    }

    for (int i = n-1; i>=0; i--)
    {
        for (auto c : {'a', 'c', '?'})
        {
            suf[c][i] = suf[c][i+1];
            if (c==s[i]) suf[c][i]++;
        }
    }

    int k = pref['?'][n];

    int full = po(3, k);
    int notfull = po(3, k-1);
    
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='b')
        {
            int prefa = pref['a'][i];
            int sufc = suf['c'][i+1];
            int prefx = pref['?'][i];
            int sufx = suf['?'][i+1];
            ans = add(ans, mul(full, mul(add(prefa, mul(prefx, inv3)), add(sufc, mul(sufx, inv3)))));
        }
        if (s[i]=='?')
        {
            int prefa = pref['a'][i];
            int sufc = suf['c'][i+1];
            int prefx = pref['?'][i];
            int sufx = suf['?'][i+1];
            ans = add(ans, mul(notfull, mul(add(prefa, mul(prefx, inv3)), add(sufc, mul(sufx, inv3)))));
        }
    }
    cout<<ans;



}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    /*int t;
    cin>>t;
    while (t--) solve();*/
    solve();


}