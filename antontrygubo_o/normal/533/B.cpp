#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}
/*
ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
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
*/
mt19937 rnd(228);

vector<vector<int>> G;

vector<ll> a;
vector<int> p;

vector<ll> even;
vector<ll> odd;

void dfs(int s)
{
    if (G[s].size()==0)
    {
        even[s] = 0;
        odd[s] = a[s];
        return;
    }
    for (auto t: G[s]) dfs(t);
    ll total = 0;
    for (auto t: G[s]) total+=even[t];
    vector<ll> temp;
    for (auto t: G[s]) temp.push_back(even[t]-odd[t]);
    sort(temp.begin(), temp.end());
    int k = temp.size();
    for (int i = 0; i<k; i++) temp[i] = -temp[i];
    ll cur = 0;
    even[s] = total;
    for (int i = 0; i<k; i++)
    {
        cur+=temp[i];
        if (i%2==1) even[s] = max(even[s], total+cur);
        else odd[s] = max(odd[s], total+cur);
    }
    odd[s] = max(odd[s], even[s] + a[s]);
    /*if (s==4)
    {
        print(G[s]);
        print(temp);
    }*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    a.resize(n+1);
    p.resize(n+1);
    G.resize(n+1);
    even.resize(n+1);
    odd.resize(n+1);
    int dir = 0;
    for (int i = 1; i<=n; i++)
    {
        cin>>p[i]>>a[i];
        if (p[i]==-1) dir = i;
        else G[p[i]].push_back(i);
    }
    dfs(dir);
    //print(a);
    cout<<max(even[dir], odd[dir])<<endl;
    //print(even);
    //print(odd);
    
}