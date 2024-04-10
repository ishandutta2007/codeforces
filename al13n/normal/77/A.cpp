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
#pragma comment (linker, "/STACK:90000000")
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000
using namespace std;

int mat[7][7];
int cost[3];
map<string,int> mpc;

int comp(string s){
    if(!mpc.count(s)){
        int t=mpc.size();
        mpc[s]=t;
    }
    return mpc[s];
}

int bitcnt(int a){
    int r=0;
    while(a){
        r+=a%2;
        a/=2;
    }
    return r;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    forn(i,n){
        string a,b;
        cin>>a>>b;
        cin>>b;
        mat[comp(a)][comp(b)]++;
    }
    forn(i,3)
        cin>>cost[i];

    pair<int,int> res=mp(iinf,iinf);
    forn(m1,1<<7){
        if(!m1)
            continue;
        forn(m2,1<<7){
            if(!m2)
                continue;
            if(m1&m2)
                continue;
            forn(m3,1<<7){
                if(!m3)
                    continue;
                if((m1&m3)||m2&m3)
                    continue;
                if((m1|m2|m3)!=(1<<7)-1)
                    continue;

                int mn=iinf,mx=-iinf;
                mn=min(mn,cost[0]/bitcnt(m1));
                mn=min(mn,cost[1]/bitcnt(m2));
                mn=min(mn,cost[2]/bitcnt(m3));
                mx=max(mx,cost[0]/bitcnt(m1));
                mx=max(mx,cost[1]/bitcnt(m2));
                mx=max(mx,cost[2]/bitcnt(m3));
                int c=0;
                forn(i,7){
                    forn(j,7){
                        if((!!(m1&(1<<i)))==(!!(m1&(1<<j)))&&(!!(m2&(1<<i)))==(!!(m2&(1<<j))))
                            c+=mat[i][j];
                    }
                }
                pair<int,int> p=mp(mx-mn,-c);
                if(p<res)
                    res=p;
            }
        }
    }
    cout<<res.first<<' '<<-res.second;

    return 0;
}