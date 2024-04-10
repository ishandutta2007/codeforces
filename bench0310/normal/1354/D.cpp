#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> tree(4*N,0);
int e=0;

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int solve(int idx,int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)/2;
    if(tree[2*idx]>=x) return solve(2*idx,l,m,x);
    else return solve(2*idx+1,m+1,r,x-tree[2*idx]);
}

void ext(int idx,int l,int r)
{
    if(l==r)
    {
        if(tree[idx]>0) e=l;
    }
    else
    {
        int m=(l+r)/2;
        ext(2*idx,l,m);
        ext(2*idx+1,m+1,r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        update(1,1,n,a,1);
    }
    while(q--)
    {
        int k;
        cin >> k;
        if(k>0) update(1,1,n,k,1);
        else update(1,1,n,solve(1,1,n,-k),-1);
    }
    ext(1,1,n);
    cout << e << "\n";
    return 0;
}