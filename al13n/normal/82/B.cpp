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

bool numdone[210];
vector<vector<int> > res;
vector<vector<int> > src;
int can[210];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    set<int> nums;
    forn(i,n*(n-1)/2){
        int l;
        cin>>l;
        src.pb(vector<int>());
        forn(i,l){
            int t;
            cin>>t;
            src.back().pb(t);
            nums.insert(t);
        }
    }

    for(set<int>::iterator it=nums.begin();it!=nums.end();++it){
        int v=*it;
        if(numdone[v])
            continue;
        forn(i,200)
            can[i+1]=0;
        res.pb(vector<int>());
        int cnt=0;
        forv(i,src){
            bool h=false;
            forv(j,src[i])
                if(src[i][j]==v){
                    h=true;
                    break;
                }
            if(!h)
                continue;
            ++cnt;
            forv(j,src[i])
                ++can[src[i][j]];
        }
        forn(i,200){
            if(can[i+1]!=cnt)
                continue;
            res.back().pb(i+1);
            numdone[i+1]=true;
        }
    }

    if(res.size()!=n){
        forn(i,n-1)
            cout<<"1 "<<res[0][i];
        cout<<endl<<res[0].size()-n+1;
        forn(i,res[0].size()-n+1)
            cout<<' '<<res[0][i+n-1];
        exit(0);
    }

    forv(i,res){
        cout<<res[i].size();
        forv(j,res[i])
            cout<<' '<<res[i][j];
        cout<<'\n';
    }

    return 0;
}