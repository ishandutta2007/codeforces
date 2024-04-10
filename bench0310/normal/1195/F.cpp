#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
const int N=100005;

int tree[4*N];

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

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v[N];
    map<pair<int,int>,int> m;
    int idx=1;
	for(int o=1;o<=n;o++)
    {
        int k;
        scanf("%d",&k);
        int x[k],y[k];
        for(int i=0;i<k;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<k;i++)
        {
            int a=y[(i+1)%k]-y[i];
            int b=x[(i+1)%k]-x[i];
            int g=__gcd(abs(a),abs(b));
            a/=g;
            b/=g;
            if(m.find({a,b})==m.end()) m[{a,b}]=idx++;
            v[o].push_back(m[{a,b}]);
        }
    }
    vector<pair<int,int>> q[N];
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[r].push_back({l,i});
    }
    vector<int> last(idx,0);
    vector<int> res(N);
    for(int i=1;i<=n;i++)
    {
        for(int a:v[i])
        {
            if(last[a]) update(1,1,n,last[a],-1);
            update(1,1,n,i,1);
            last[a]=i;
        }
        for(pair<int,int> p:q[i])
        {
            res[p.second]=query(1,1,n,p.first,i);
        }
    }
    for(int i=0;i<t;i++) printf("%d\n",res[i]);
	return 0;
}