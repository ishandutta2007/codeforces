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
#define SQ(a) ((a)*(a))

int src[1100];
int n;
pair<int,pair<int,pair<int,int> > > dp[1100][1100];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    forn(i,n)
        cin>>src[i];

    memset(dp,-1,sizeof(dp));
    dp[1][0]=mp(0,mp(0,mp(0,0)));
    int k;
    for(k=1;n-k+1>=3;k+=2){
        forn(p,n){
            if(dp[k][p].first==-1)
                continue;
            int vv[3]={p,k,k+1};
            int v[3]={src[p],src[k],src[k+1]};
            int s=p+k+k+1;
            forn(i,2)
                for(int j=i+1;j<3;++j){
                    pair<int,pair<int,pair<int,int> > > &t=dp[k+2][s-vv[i]-vv[j]];
                    int q=dp[k][p].first+max(v[i],v[j]);
                    pair<int,pair<int,pair<int,int> > > w=mp(q,mp(p,mp(vv[i],vv[j])));
                    if(t.first==-1||t.first>q)
                        t=w;
                }

        }
    }
    
    int res=iinf*2;
    vector<pair<int,int> > resv;
    int p=-1;
    forn(i,n)
        if(dp[k][i].first!=-1){
            int t=dp[k][i].first+((k<n)?max(src[k],src[i]):src[i]);
            if(t<res){
                res=t;
                p=i;
                resv.clear();
                resv.pb(mp(k,i));
            }
        }
    if(p==-1)
        exit(123);
    while(k>1){
        resv.pb(dp[k][p].second.second);
        p=dp[k][p].second.first;
        k-=2;
    }

    reverse(all(resv));
    cout<<res;
    forv(i,resv){
        cout<<'\n';
        if(resv[i].first<n)
            cout<<resv[i].first+1<<' ';
        cout<<resv[i].second+1;
    }

    return 0;
}