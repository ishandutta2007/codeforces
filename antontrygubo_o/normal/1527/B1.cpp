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
const int LIM = 1000;

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


/*struct DSU
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

const int N = 1000;

int dp[N][N][2][2];

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int cnt00 = 0;
    int cnt01 = 0;
    int cnt0 = 0;
    if (n%2==1 && s[n/2]=='0') cnt0++;
    for (int i = 0; i<n/2; i++)
    {
        int j = n-1-i;
        if (s[i]=='0' && s[j]=='0') cnt00++;
        if (s[i]!=s[j]) cnt01++;
    }

    int bal = dp[cnt00][cnt01][cnt0][0];

    //cout<<cnt00<<' '<<cnt01<<' '<<cnt0<<": "<<bal<<endl;

    if (bal>0) cout<<"ALICE"<<endl;
    else if (bal==0) cout<<"DRAW"<<endl;
    else cout<<"BOB"<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for (int cnt00 = 0; cnt00<N; cnt00++)
        for (int cnt01 = 0; cnt01<N; cnt01++)
            for (int cnt0 = 0; cnt0<2; cnt0++)
                for (int reversed = 1; reversed>=0; reversed--)
                {
                    if (cnt00+cnt01+cnt0 == 0) continue;
                    int best = -1e9;
                    if (cnt00>0) best = max(best, -dp[cnt00-1][cnt01+1][cnt0][0] - 1);
                    if (cnt01>0) best = max(best, -dp[cnt00][cnt01-1][cnt0][0] - 1);
                    if (cnt0>0) best = max(best, -dp[cnt00][cnt01][cnt0-1][0] - 1);
                    if (reversed==0 && cnt01>0) best = max(best, -dp[cnt00][cnt01][cnt0][1]);
                    dp[cnt00][cnt01][cnt0][reversed] = best;
                }

    int t; cin>>t;
    while (t--) solve();
}

/*Palindrome -> Bob
 Proof by induction:
 Alice makes 0->1
 Bob reverses???

 0000:
 1000 Alice makes
 0001 Bob reverses
 1001 Alice makes
 1101 Bob makes
 1011 Alice reverses
 1111 Bob makes

*/