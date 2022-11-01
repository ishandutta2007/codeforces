#include <bits/stdc++.h>

using namespace std;

const int N=200001;
vector<int> p(N);
vector<int> sz(N);
vector<int> t(N);

void make_set(int a)
{
    p[a]=a;
    sz[a]=1;
    t[a]=a;
}

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

int merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return 0;
    if(sz[a]<sz[b]) swap(a,b);
    t[a]=max(t[a],t[b]);
    p[b]=a;
    return 1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) make_set(i);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        merge_sets(a,b);
    }
    int res=0;
    int idx=1;
    while(idx<=n)
    {
        while(idx<t[find_set(idx)])
        {
            res+=merge_sets(idx,idx+1);
            idx++;
        }
        idx++;
    }
    printf("%d\n",res);
    return 0;
}