#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
const int inf=(1<<29);
vector<int> tree(4*N,inf);
vector<int> lazy(4*N,0);

void push(int idx)
{
    for(int i=0;i<2;i++)
    {
        tree[2*idx+i]+=lazy[idx];
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 2*inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) h[p[i]]=i;
    vector<int> q(n+1,0);
    for(int i=1;i<=n;i++) cin >> q[i];
    int now=n;
    for(int i=1;i<=n;i++)
    {
        //mv
        while(query(1,1,n,h[now],h[now])>=inf+1&&query(1,1,n,1,h[now]-1)>0)
        {
            update(1,1,n,h[now],h[now],-(inf+1));
            update(1,1,n,1,h[now]-1,-1);
            now--;
        }
        cout << now << " \n"[i==n];
        //add bomb
        update(1,1,n,1,q[i],1);
    }
    return 0;
}