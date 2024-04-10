#pragma comment (linker, "/STACK:90000000")
#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000

int n;
int k;
int X[100];
int A[1000];
int l;
int dist[11000];
int wei[30][30];

void bfs(int v){
    memset(dist,-1,sizeof(dist));
    queue<int> qu;
    dist[v]=0;
    qu.push(v);
    while(!qu.empty()){
        v=qu.front();
        qu.pop();
        int d=dist[v];
        forn(i,l){
            int t=A[i];
            if(v-t>=0&&dist[v-t]==-1){
                dist[v-t]=d+1;
                qu.push(v-t);
            }
            if(v+t<=n&&dist[v+t]==-1){
                dist[v+t]=d+1;
                qu.push(v+t);
            }
        }
    }
}

int dp[1<<22];
//int dp[100];

inline int bitcnt(int a){
    int r=0;
    while(a){
        r+=a&1;
        a>>=1;
    }
    return r;
}

int asd[11000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n>>k>>l;
    
    forn(i,k)
        cin>>X[i],--X[i],asd[X[i]]=true;
    sort(X,X+k);
    k=unique(X,X+k)-X;
    int tmp[20];
    memcpy(tmp,X,sizeof(tmp));
    int t=k;
    k=0;
    if(!tmp[0])
        X[k++]=0;
    if(tmp[t-1]==n-1)
        X[k++]=n;
    forn(i,t){
        if(tmp[i]&&!asd[tmp[i]-1])
            X[k++]=tmp[i];
        if(tmp[i]<n-1&&!asd[tmp[i]+1])
            X[k++]=tmp[i]+1;
    }
    sort(X,X+k);

    forn(i,l)
        cin>>A[i];

    sort(A,A+l);
    l=unique(A,A+l)-A;

    if(k>22)
        exit(123);

    forn(i,k){
        bfs(X[i]);
        forn(j,k)
            wei[i][j]=dist[X[j]];
    }

    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    forn(m,1<<k){
        if(bitcnt(m)%2)
            continue;
        if(dp[m]==-1)
            continue;
        int tm=-1;
        int p1;
        forn(i,k){
            if(m&(1<<i))
                continue;
            if(tm!=-1){
                int t=tm|(1<<i);
                if(wei[p1][i]!=-1&&(dp[t]==-1||dp[t]>dp[m]+wei[p1][i]))
                    dp[t]=dp[m]+wei[p1][i];
            }else
                tm=m|(1<<i),
                p1=i;
        }
    }

    cout<<dp[(1<<k)-1];

    return 0;
}