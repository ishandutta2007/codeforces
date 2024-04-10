#include<bits/stdc++.h>
using namespace std;
vector<pair< pair<int, int> , int> > V;
vector<int> V2;
int N;
const int MAXN = 131072;
long long int idx[2*MAXN];
long long int getv(int l, int r)
{
    l+= MAXN;
    r+=MAXN;
    long long ans = 0;
    while(l<=r)
    {
        if(l%2==1) ans=max(ans, idx[l++]);
        if(r%2==0) ans=max(ans, idx[r--]);
        l/=2; r/=2;
    }
    return ans;
}
void setv(int a, long long int v)
{
    a+=MAXN;
    idx[a] = v;
    while(a!=1)
    {
        a/=2;
        idx[a]=max(idx[2*a],idx[2*a+1]);
    }
    return ;
}
bool cmp(pair< pair<int, int> , int> a, pair< pair<int, int> , int> b)
{
    if(a.first.second<b.first.second) return true;
    if(a.first.second>b.first.second) return false;
    return a.first.first<b.first.first;
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        V.emplace_back(make_pair(a,b), c);
        V2.emplace_back(b);
    }
    sort(V.begin(), V.end(), cmp);
    sort(V2.begin(), V2.end());
    for(int i=0; i<N; ++i)
    {
        int stidx = lower_bound(V2.begin(), V2.end(),V[i].first.first+1)-V2.begin();   
        int edidx = i-1;
        setv(i, getv(stidx, edidx)+V[i].second);
    }
    printf("%lld\n", getv(0, N-1));
}