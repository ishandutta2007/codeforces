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



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    //ios_base::sync_with_stdio(false);
    
    map<int,int> cnts;
    int n;
    cin>>n;
    forn(i,n){
        int a;
        cin>>a;
        ++cnts[a];
    }
    priority_queue<pair<int,int> > qu;
    for(map<int,int>::iterator it=cnts.begin();it!=cnts.end();++it){
        qu.push(mp(it->second, it->first));
    }
    vector<pair<pair<int,int>,int> > res;
    while(qu.size()>=3) {
        pair<int,int> a = qu.top();
        qu.pop();
        pair<int,int> b = qu.top();
        qu.pop();
        pair<int,int> c = qu.top();
        qu.pop();
        res.pb(mp(mp(a.second,b.second),c.second));
        --a.first;
        --b.first;
        --c.first;
        if(a.first)
            qu.push(a);
        if(b.first)
            qu.push(b);
        if(c.first)
            qu.push(c);
    }
    cout<<res.size()<<endl;
    forv(i,res){
        int a=res[i].first.first;
        int b=res[i].first.second;
        int c=res[i].second;
        if(a<b)
            swap(a,b);
        if(b<c)
            swap(b,c);
        if(a<b)
            swap(a,b);
        cout<<a<<' '<<b<<' '<<c<<'\n';
    }
    
    return 0;
}