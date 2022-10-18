#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

#define TASK "test"

const int maxn=1e6+100;

int cnt[2][maxn],sum[2][maxn];

long long ans=0;

void merge_sort(int l,int r)
{
    if(l==r) return;
    vector<int> tmp[3];
    tmp[0]=tmp[1]=tmp[2]=vector<int>(r-l);
    int m=(l+r)/2;
    merge_sort(l,m);
    if(l!=m) merge_sort(m,r);

    int p1[3]={l,l,l},p2[3]={m,m,m};

    for(int z=l;z<r;z++)
    {
        for(int j=0;j<2;j++)
        {
            int t=0;
            if(p1[j]==m) t=sum[j][p2[j]++];
            else if(p2[j]==r) t=sum[j][p1[j]++];
            else if(sum[j][p1[j]]<sum[j][p2[j]]) t=sum[j][p1[j]++];
            else t=sum[j][p2[j]++];
            tmp[j][z-l]=t;
        }
        if(p1[2]==m || p2[2]==r) continue;
        if(sum[1][p2[2]]<sum[0][p1[2]])
            p2[2]++,
            ans+=m-p1[2];
        else
            p1[2]++;
    }

    for(int i=l;i<r;i++)
        sum[0][i]=tmp[0][i-l],
        sum[1][i]=tmp[1][i-l];
}

main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it:a) cin>>it;
    vector<int> c(a);
    vector<int> b(n);
    iota(b.begin(),b.end(),0);
    sort(b.begin(),b.end(),[&](int f,int s){return a[f]<a[s];});
    int t=1;
    for(int i=0;i<n;i++)
    {
        if(i && c[b[i]]!=c[b[i-1]]) t++;
        a[b[i]]=t;
    }
    for(int i=0;i<n;i++)
    {
        sum[0][i]=++cnt[0][a[i]];
        sum[1][n-i-1]=++cnt[1][a[n-i-1]];
    }
    merge_sort(0,n);
    cout<<ans<<endl;
 }