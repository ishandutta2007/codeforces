#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, c;
int a[N], pref[N], cache[N], st[4*N];

void build(int node, int L, int R)
{
    if(L==R)
    {
        st[node]=a[L];
        return;
    }
    int M=(L+R)>>1;
    build(node*2, L, M);
    build(node*2 + 1, M+1, R);
    st[node]=min(st[node*2], st[node*2+1]);
}

int query(int node, int L, int R, int i, int j)
{
    if(j<L || i>R)
        return 1e10;
    if(i<=L && R<=j)
        return st[node];
    int M=(L+R)>>1;
    int left=query(node*2, L, M, i, j);
    int right=query(node*2 + 1, M+1, R, i, j);
    return min(left, right);
}  

int getsum(int l, int r)
{
    return pref[r]-pref[l-1];
}

int dp(int i)
{
    if(i>n)
        return 0;
    if(cache[i]!=-1)
        return cache[i];
    int &ans=cache[i];
    if(i+c-1>n)
    {
        ans=getsum(i, n);
    }
    else
    {
        ans=min(a[i] + dp(i+1), getsum(i, i+c-1) - query(1, 1, n, i, i+c-1) + dp(i+c));
    }
    return ans;
}

int32_t main()
{
    memset(cache, -1, sizeof(cache));
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pref[i]=a[i]+pref[i-1];
    }
    build(1, 1, n);
    cout<<dp(1);
    return 0;
}