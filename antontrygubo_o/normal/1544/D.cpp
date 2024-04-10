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
   int n; cin>>n;
   vector<int> a(n); for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}

   set<int> vals; for (auto it: a) vals.insert(it);

   if(vals.size()==n)
   {
       cout<<n<<endl;
       for (auto it: a) cout<<it+1<<' ';
       cout<<endl; return;
   }

   vector<vector<int>> want(n);
   for (int i = 0; i<n; i++) want[a[i]].push_back(i);

   int popular = 0;
   while (want[popular].size()<2) popular++;

   set<int> givers; set<int> receivers;

   for (int i = 0; i<n; i++)
   {
       givers.insert(i); receivers.insert(i);
   }

   cout<<vals.size()<<endl;

   vector<int> ans(n, -1);

   for (int i = 0; i<n; i++) if (i!=popular && want[i].size()>0)
   {
        int giver = want[i][0];
        ans[giver] = i;
        givers.erase(giver);
        receivers.erase(i);
   }

   //Processing popular;

   /*for (auto it: ans) cout<<it<<' ';
   cout<<endl;*/

   int giver;

   if (givers.size()==2)
   {
       int cand1 = want[popular][0];
       int cand2 = want[popular][1];

       //Trying cand1;
       givers.erase(cand1); receivers.erase(popular);
       if ((*givers.begin()) == (*receivers.begin()))
       {
           giver = cand2;
           givers.insert(cand1); givers.erase(cand2);
       }
       else giver = cand1;
   }

   else
   {
       giver = want[popular][0];
       givers.erase(giver);
       receivers.erase(popular);
   }

   ans[giver] = popular;

   //cout<<giver<<endl;

   vector<int> give, receive;

   for (int i = 0; i<n; i++)
   {
       if (givers.count(i) && receivers.count(i))
       {
           give.push_back(i); receive.push_back(i);
           givers.erase(i); receivers.erase(i);
       }
   }

   for (auto it: givers) give.push_back(it);
   for (auto it: receivers) receive.push_back(it);

   int k = give.size();

   for (int i = 0; i<k; i++) ans[give[i]] = receive[(i+1)%k];

   for (auto it: ans) cout<<it+1<<' ';
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