#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1<<17;
int N;
int arr[MAXN];
int idx[2*MAXN];
void setv(int a, int v)
{
    arr[a] = v;
    a += MAXN;
    idx[a] = a-MAXN;
    while(a = a/2)
    {
        if(arr[idx[2*a]]>arr[idx[2*a+1]])
            idx[a] = idx[2*a];
        else
            idx[a] = idx[2*a+1]; 
    }
}
int getv(int a, int b)
{
    int maxi = MAXN-1;
    a += MAXN; b+= MAXN;
    while(a<=b)
    {
        if(a%2==1)
        {
            if(arr[idx[a]]>arr[idx[maxi]]) maxi = idx[a];
            a++;
        }
        if(b%2==0)
        {
            if(arr[idx[b]]>arr[idx[maxi]]) maxi = idx[b];
            b--;
        }
        a/=2; b/=2;
    }
    return maxi;
}

vector<int> V[MAXN];


int main()
{
    for(int i=0; i<MAXN; ++i) setv(i, 0);
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; ++i)
    {
        int t;
        scanf("%d", &t);
        V[t].push_back(i);
    }
    
    int lastidx = -1;
    for(int i=1; i<MAXN; ++i)
    {
        for(auto& x: V[i])
            if(x < lastidx) x += N;
        sort(V[i].begin(), V[i].end());
        for(auto& x: V[i])
            if(x >= N) x -= N;
        for(int idx: V[i])
        {
            
            int ai = getv(0, MAXN-1);
            int vv = arr[ai];
            if(ai>idx)++vv;
            //printf("%d %d\n", idx,vv);
            setv(idx, vv);
            lastidx = idx;
        }
    }
    
    /*
    sort(V.begin(), V.end());
    for(auto x: V)
    {
        int idx = x.second;
        int ai = getv(0, MAXN-1);
        int vv = arr[ai];
        if(ai>idx) ++vv;
        setv(idx, vv);
    }
    */
    long long ans = 0;
    for(int i=0; i<N; ++i)
        ans += arr[i];
    printf("%lld\n", ans);
}