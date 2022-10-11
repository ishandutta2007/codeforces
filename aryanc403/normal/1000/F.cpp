#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 500001;
const int R = 708;

struct mytype
{
    int l,r,i;
}q[N];
    int ans[N],a[N],cnt[N],blk[R],sz=0;

bool cmp(const mytype &a,const mytype &b)
{
    if(a.l/R!=b.l/R)
        return a.l<b.l;
    if((a.l/R)&1)
        return a.r>b.r;
    return a.r<b.r;
}

inline void add(int n)
{
    int val=a[n];
    cnt[val]++;
    if(cnt[val]==1)
    {
        sz++;
        blk[val/R]++;
    }
    else if(cnt[val]==2)
    {
        sz--;
        blk[val/R]--;
    }
}

inline void del(int n)
{
    int val=a[n];
    cnt[val]--;
    if(cnt[val]==1)
    {
        sz++;
        blk[val/R]++;
    }
    else if(!cnt[val])
    {
        sz--;
        // cout<<"del "<<val<<"|\n";
        blk[val/R]--;
    }
}
inline int solve()
{
    if(sz==0)
        return 0;
    for(int i=0;i<R;i++)
    {
        if(blk[i]>0)
        {
            for(int j=i*R;j<i*R+R;j++)
            {
                if(cnt[j]==1)
                    return j;
            }
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;//scanf(" %d",&n);
    for(int i=0;i<n;i++)
        cin>>a[i];//scanf(" %d",&a[i]);
    int nq;
    cin>>nq;//scanf(" %d",&nq);
    int l,r;
    for(int i=0;i<nq;i++)
    {
        cin>>l>>r;//scanf(" %d %d",&q[i].l,&q[i].r);
        l--;r--;
        q[i].l=l;q[i].r=r;
        q[i].i=i;
    }
    
    sort(q,q+nq,cmp);
    l=0;r=-1;
    for(int i=0;i<nq;++i)
    {
        int L=q[i].l,R=q[i].r;
        while(r<R)
        {
            r++;
            add(r);
        }
        
        while(l>L)
        {
            l--;
            add(l);
        }
        
        while(r>R)
        {
            del(r);
            r--;
        }
        
        while(l<L)
        {
            del(l);
            l++;
        }
        ans[q[i].i]=solve();
    }
    
    for(int i=0;i<nq;++i)
        cout<<ans[i]<<'\n';//printf("%d\n",ans[i]);
    
    return 0;
}