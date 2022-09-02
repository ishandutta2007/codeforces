#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX*/

using namespace std;

using ll = long long;

#define mp make_pair

const int p = 998244353;


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

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*const int N = 1000000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

void solve()
{
    string s;
    cin>>s;
    int maxx = 0;
    int n = s.size();
    while (s[maxx]==s[n-1-maxx] && maxx<n-1-maxx) maxx++;

    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }

    /*for (auto it: d1) cout<<it<<' ';
    cout<<endl;
    for (auto it: d2) cout<<it<<' ';
    cout<<endl;*/

    int best = -1;
    int way = -1;
    int ans = -1;

    for (int i = 0; i<n; i++)
    {
        int l = i - d1[i] + 1;
        int r = n - i - d1[i];
        if (maxx>=min(l, r) && 2*min(l, r) + (2*d1[i] - 1)>ans)
        {
            best = i; way = 0; ans = 2*min(l, r) + (2*d1[i] - 1);
        }
    }

    for (int i = 1; i<n; i++)
    {
        int l = i - d2[i];
        int r = n - i - d2[i];
        if (maxx>=min(l, r) && 2*min(l, r) + 2*d2[i]>ans)
        {
            best = i; way = 1; ans = 2*min(l, r) + 2*d2[i];
        }
    }

    //cout<<best<<' '<<way<<' '<<ans<<endl;

    if (way==0)
    {
        int i = best;
        int l = i - d1[i] + 1;
        int r = n - i - d1[i];
        cout<<s.substr(0, min(l, r)) + s.substr(i - d1[i]+1, 2*d1[i]-1) + s.substr(n - min(l, r), min(l, r))<<'\n';
    }
    else
    {
        int i = best;
        int l = i - d2[i];
        int r = n - i - d2[i];
        cout<<s.substr(0, min(l, r)) + s.substr(i - d2[i], 2*d2[i]) + s.substr(n - min(l, r), min(l, r))<<'\n';
    }



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}