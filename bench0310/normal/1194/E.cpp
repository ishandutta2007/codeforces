#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
const int N=10001;

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

long long sum(long long a)
{
    return (a*(a-1)/2ll);
}

int main()
{
    int n;
    scanf("%d",&n);
	vector<vector<int>> v; //lower,upper,x
	vector<vector<int>> h; //y,left,right
	for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a+=5001;
        b+=5001;
        c+=5001;
        d+=5001;
        if(a>c) swap(a,c);
        if(b>d) swap(b,d);
        if(a==c) v.push_back(vector<int>{b,d,a});
        if(b==d) h.push_back(vector<int>{b,a,c});
    }
    sort(v.begin(),v.end());
    sort(h.begin(),h.end());
    long long res=0;
    for(int o=0;o<(int)h.size();o++)
    {
        //Clean segment tree
        memset(tree,0,sizeof tree);
        //Set up vertical segments
        int y=h[o][0];
        set<pair<int,int>> s; //upper,x
        for(int i=0;i<(int)v.size();i++)
        {
            if(v[i][0]<=y)
            {
                s.insert(make_pair(v[i][1],v[i][2]));
                update(1,1,N,v[i][2],1);
            }
            else break;
        }
        //Solve
        for(int i=o+1;i<(int)h.size();i++)
        {
            int now=h[i][0];
            while((!s.empty())&&(*s.begin()).first<now)
            {
                update(1,1,N,(*s.begin()).second,-1);
                s.erase(s.begin());
            }
            int l=max(h[o][1],h[i][1]);
            int r=min(h[o][2],h[i][2]);
            res+=sum(query(1,1,N,l,r));
        }
    }
    printf("%I64d\n",res);
	return 0;
}