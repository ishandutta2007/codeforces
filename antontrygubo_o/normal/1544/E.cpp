#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

int MOD =  1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 300000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
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

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

void solve()
{
    string s; cin>>s;
    sort(s.begin(), s.end());

    int n = s.size();
    vector<int> cnt(26);
    for (auto c: s) cnt[c-'a']++;

    if (s[0] == s[n-1]) {cout<<s<<endl; return;}

    for (int i = 0; i<26; i++) if (cnt[i]==1)
    {
        cout<<char('a'+i); cnt[i]--;
        for (int j = 0; j<26; j++)
        {
            while (cnt[j]>0)
            {
                cout<<char('a'+j); cnt[j]--;
            }
        }
        cout<<endl; return;
    }

    int minn = 0;
    while (cnt[minn] == 0) minn++;

    if (2*(n-cnt[minn])>=(n-2))
    {
        cout<<char('a'+minn)<<char('a'+minn);

        cnt[minn]-=2;

        queue<char> good;
        for (int i = 0; i<26; i++) if (i!=minn)
        {
            while (cnt[i])
            {
                good.push(char('a'+i)); cnt[i]--;
            }
        }


        while (cnt[minn])
        {
            char c = good.front();
            good.pop();
            cout<<c<<char('a'+minn);
            cnt[minn]--;
        }
        while (!good.empty())
        {
            char c = good.front();
            good.pop();
            cout<<c;
        }
        cout<<endl;
        return;
    }

    int min1 = minn+1;
    while (cnt[min1]==0) min1++;

    cout<<char('a'+minn)<<char('a'+min1);

    cnt[minn]--; cnt[min1]--;

    vector<char> other;
    for (int i = 0; i<26; i++) if (i!=minn && i!=min1)
    {
        while (cnt[i])
        {
            other.push_back(char('a'+i)); cnt[i]--;
        }
    }

    if (other.size()==0)
    {
        while (cnt[min1])
        {
            cout<<char('a'+min1); cnt[min1]--;
        }
        while (cnt[minn])
        {
            cout<<char('a'+minn); cnt[minn]--;
        }
        cout<<endl; return;
    }

    while (cnt[minn])
    {
        cout<<char('a'+minn); cnt[minn]--;
    }

    cout<<other[0];
    while (cnt[min1])
    {
        cout<<char('a'+min1); cnt[min1]--;
    }
    for (int i = 1; i<other.size(); i++) cout<<other[i];
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();


}

/*
1
3
2 1 2
 */