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
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> v[q+1];
	int f=-1;
	bool big=0;
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(f==-1&&a[i]!=0) f=a[i];
        if(a[i]==q) big=1;
        v[a[i]].push_back(i);
        if(a[i]==0) a[i]=q+1;
    }
    build(1,1,n);
    bool ok=1;
    for(int i=q;i>=1;i--)
    {
        if(v[i].empty()) continue;
        if(query(1,1,n,v[i][0],v[i].back())<i) ok=0;
    }
    if(f==-1) f=1;
    if(big==0&&v[0].empty()) ok=0;
    if(big==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==q+1)
            {
                a[i]=q;
                break;
            }
        }
    }
    else if(a[1]==q+1) a[1]=f;
    for(int i=2;i<=n;i++) if(a[i]==q+1) a[i]=a[i-1];
    if(ok)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
    }
    else printf("NO\n");
	return 0;
}