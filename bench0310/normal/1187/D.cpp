#include <bits/stdc++.h>

using namespace std;
const int N=300005;

int tree[4*N];
queue<int> q[N];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        if(q[l].empty()) tree[idx]=N;
        else tree[idx]=q[l].front();
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return N;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) q[a[i]].push(i);
        build(1,1,n);
        bool res=1;
        for(int i=1;i<=n;i++)
        {
            if(q[b[i]].empty())
            {
                res=0;
                break;
            }
            if(query(1,1,n,1,b[i]-1)<q[b[i]].front())
            {
                res=0;
                break;
            }
            q[b[i]].pop();
            if(q[b[i]].empty()) update(1,1,n,b[i],N);
            else update(1,1,n,b[i],q[b[i]].front());
        }
        for(int i=1;i<=n;i++) while(!q[i].empty()) q[i].pop();
        if(res) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}