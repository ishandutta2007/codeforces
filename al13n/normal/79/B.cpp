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



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<pair<int,int> > vec;
    forn(i,k){
        int a,b;
        cin>>a>>b;
        vec.pb(mp(a,b));
    }
    sort(all(vec));
    
    string asd[]={"Carrots", "Kiwis","Grapes"};
    forn(i,t){
        int a,b;
        cin>>a>>b;
        int q=lower_bound(all(vec),mp(a,b))-vec.begin();
        if(q<vec.size()&&vec[q]==mp(a,b))
            cout<<"Waste\n";
        else
            cout<<asd[((a-1)*m+(b-1)-q)%3]<<'\n';
    }

    return 0;
}