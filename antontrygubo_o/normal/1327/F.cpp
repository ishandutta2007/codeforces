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


const int N = 6e5;
vector<int> degs(N);


int solve(int n, vector<pair<int, int>> zero, vector<pair<int, int>> one)
{
    vector<int> a(n);
    vector<int> st(n);
    vector<int> en(n);
    for (auto it: one)
    {
    st[it.first]++;
    en[it.second]++;
    }
    int cur = 0;
    for (int i = 0; i<n; i++)
    {
    cur+=st[i];
    if (cur>0) a[i] = 1;
    cur-=en[i];
    }
    vector<int> zeros(n);
    cur = 0;
    for (int i = 0; i<n; i++)
    {
    if (a[i]==0) cur++;

    zeros[i] = cur;
    }

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;

    for (auto it: zeros) cout<<it<<' ';
    cout<<endl;*/

    for (auto &it: zero)
    {
    if (a[it.first]==0) it.first = zeros[it.first]-1;
    else it.first = zeros[it.first];
    it.second = zeros[it.second]-1;
    if (it.first>it.second||it.second>=cur) return 0;
    it.second++;
    //cout<<it.first<<' '<<it.second<<endl;
    }




    if (zero.size()==0) return degs[cur];


    vector<bool> guys(cur + 2);

    for (auto &it: zero)
    {
    guys[it.first] = true;
    guys[it.second] = true;
    }

    guys[cur] = true;
    guys[0] = true;

    vector<int> checkpoints;
    for (int i = 0; i<guys.size(); i++) if (guys[i]) checkpoints.push_back(i);

    int k = checkpoints.size();
    vector<int> pref(k);
    vector<int> ans(k);
    int current = 0;
    int bad = -1;
    pref[0] = 1;
    ans[0] = 1;
    for (int i = 1; i<k; i++)
    {
    while (current<zero.size() && zero[current].second<=checkpoints[i-1]) current++;
    if (current>0) while (bad+1<k && checkpoints[bad+1]<=zero[current-1].first) bad++;
    ans[i] = pref[i-1];
    if (bad>=0) ans[i] = sub(ans[i], pref[bad]);
    ans[i] = mul(ans[i], sub(degs[checkpoints[i] - checkpoints[i-1]], 1));
    pref[i] = add(pref[i-1], ans[i]);
    }
    int res = 0;
    for (int i = 1; i<k; i++) if (checkpoints[i-1]>=zero[zero.size()-1].first) res = add(res, ans[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    degs[0] = 1;
    for (int i = 1; i<N; i++) degs[i] = mul(degs[i-1], 2);

    int n, k, m;
    cin>>n>>k>>m;

    vector<pair<pair<int, int>, int>> a(m);
    for (int i = 0; i<m; i++)
    {
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
        a[i].first.first--; a[i].first.second--;
        a[i].first.second*=-1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i<m; i++)
    {
        a[i].first.second*=-1;
    }

    int ans = 1;

    for (int bit = 0; bit<k; bit++)
    {
        vector<pair<int, int>> one;
        vector<pair<int, int>> zero;
        stack<pair<int, int>> temp;

        for (auto it: a)
        {
            if (it.second & (1<<bit)) one.push_back(it.first);
            else
            {
                while (!temp.empty() && temp.top().second>=it.first.second) temp.pop();
                temp.push(it.first);
            }
        }
        while (!temp.empty())
        {
            zero.push_back(temp.top());
            temp.pop();
        }
        reverse(zero.begin(), zero.end());

        /*cout<<endl<<"bit: "<<bit<<endl;
        cout<<"Zero:\n";
        for (auto it: zero) cout<<it.first<<' '<<it.second<<endl;
        cout<<"One:\n";
        for (auto it: one) cout<<it.first<<' '<<it.second<<endl;*/

        int kek = solve(n, zero, one);

        //cout<<"ans: "<<kek<<endl;
        ans = mul(ans, kek);
    }
    cout<<ans;


}