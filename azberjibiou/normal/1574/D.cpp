#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pmax pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=200020;
const int mxM=10001000;
const int mxK=40;
const ll MOD=998244353;
const ll P1=1000000007, P2=10000000009;
const ll INF=8000000000000000001;
int N, M;
vector <int> v[mxN];
map <pll, char> ban;
typedef struct a10{
    int a[11]={};
    const bool operator<(const a10 b) const
    {
        for(int i=0;i<11;i++)   if(a[i]!=b.a[i])    return a[i]<b.a[i];
        return false;
    }
}a10;

typedef struct cmp1{
    bool operator()(a10 v1, a10 v2)
    {
        return v1.a[10]<v2.a[10];
    }
}cmp1;

priority_queue <a10, vector<a10>, cmp1> pq;
map <a10, int> Chk;

pll hashing(a10 now)
{
    ll t1=0, t2=0;
    for(int i=0;i<N;i++)
    {
        t1=v[i].size()*t1+now.a[i];
        t2=v[i].size()*t2+now.a[i];
        t1%=MOD;
        t2%=P2;
    }
    return {t1, t2};
}

int main()
{
    gibon
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int k;
        cin >> k;
        v[i].resize(k);
        for(int j=0;j<k;j++)    cin >> v[i][j];
    }
    cin >> M;
    a10 tmp, tmpp;
    while(M--)
    {
        for(int i=0;i<N;i++)    cin >> tmp.a[i];
        for(int i=0;i<N;i++)    tmp.a[i]--;
        ban[hashing(tmp)]++;
    }
    for(int i=0;i<N;i++)    tmp.a[i]=v[i].size()-1;
    for(int i=0;i<N;i++)    tmp.a[10]+=v[i][tmp.a[i]];
    pq.push(tmp);
    Chk[tmp]=1;
    while(true)
    {
        a10 now=pq.top();
        pq.pop();
        pll hashnow=hashing(now);
        if(ban[hashnow]==0)
        {
            for(int i=0;i<N;i++)    cout << now.a[i]+1 << " ";
            return 0;
        }
        for(int i=0;i<=10;i++)    tmpp.a[i]=now.a[i];
        for(int i=0;i<N;i++)
        {
            if(now.a[i]!=0)
            {
                tmpp.a[i]=now.a[i]-1;
                tmpp.a[10]-=v[i][now.a[i]]-v[i][now.a[i]-1];
                if(Chk[tmpp]!=1)    pq.push(tmpp);
                Chk[tmpp]=1;
                //printf("tmpp=%d, %d, %d\n", tmpp.a[0], tmpp.a[1], tmpp.a[2]);
                tmpp.a[i]=now.a[i];
                tmpp.a[10]+=v[i][now.a[i]]-v[i][now.a[i]-1];
            }
        }
    }
}