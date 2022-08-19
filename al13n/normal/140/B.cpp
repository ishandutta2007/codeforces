#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#include <memory.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define div asddiv
#define eps 1e-11
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;

int iperm[310];
int iperms[310][310];
int n;
pair<int, int> res[310];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    //ios_base::sync_with_stdio(false);
    
    memset(res,-1,sizeof(res));
    cin>>n;
    forn(i,n) {
        forn(j,n) {
            int a;
            cin >> a;
            --a;
            iperms[i][a]=j;
        }
    }
    forn(i,n){
        int a;
        cin>>a;
        --a;
        iperm[a] = i;
    }
    
    vector<pair<int,int> > cur;
    for (int i = 0; i < n;++i){
        cur.pb(mp(iinf-iperm[i], i));
        sort(all(cur));
        reverse(all(cur));
        forn(j,n){
            int c=cur[0].second;
            if(c==j){
                if(cur.size()==1)
                    continue;
                c=cur[1].second;
            }
            int t=iperms[j][c];
            res[j]=max(res[j],mp(iinf-t,i));
        }
    }
    
    forn(i,n)
        cout<<res[i].second+1 << ' ';
    
    return 0;
}