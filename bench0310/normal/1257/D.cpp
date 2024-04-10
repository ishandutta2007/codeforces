#include <bits/stdc++.h>

using namespace std;

const int N=200005;
int a[N];
int tree[4*N];


void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=a[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        vector<pair<int,int>> v(m);
        for(int i=0;i<m;i++) scanf("%d%d",&v[i].first,&v[i].second);
        sort(v.begin(),v.end());
        map<int,int> id;
        for(int i=m-1;i>=0;i--) id[v[i].first]=i;
        vector<int> best(m,0);
        for(int i=m-1;i>=0;i--)
        {
            best[i]=v[i].second;
            if(i!=m-1) best[i]=max(best[i],best[i+1]);
        }
        build(1,1,n);
        if(v[m-1].first<query(1,1,n,1,n))
        {
            printf("-1\n");
            continue;
        }
        int now=1;
        int res=0;
        while(now<=n)
        {
            int l=now;
            int r=n+1;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(best[(*id.lower_bound(query(1,1,n,now,m))).second]>=(m-now+1)) l=m;
                else r=m;
            }
            now=l+1;
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}