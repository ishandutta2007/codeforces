#pragma comment(linker,"/STACK:228000000")
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
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define lng long long
#define ulng unsigned long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y0 asdy0
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
#define ends asdends
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h" // project euler thingy
#endif

struct state{
    int h[4];
    state(){}
    bool operator<(const state &b)const{
        forn(i,4)
            if(h[i]!=b.h[i])
                return h[i]<b.h[i];
        return false;
    }
    bool operator==(const state &b)const{
        forn(i,4)
            if(h[i]!=b.h[i])
                return false;
        return true;
    }
};

const char *names[4]={"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    static char line[100000];
    gets(line);
    gets(line);
    vector<state> st;
    state t;
    memset(&t,0,sizeof(t));
    st.pb(t);
    int ind[256];
    ind['G']=0;
    ind['H']=1;
    ind['R']=2;
    ind['S']=3;
    forn(i,n){
        vector<state> pr=st;
        st.clear();
        forv(j,pr){
            t=pr[j];
            if(line[i]=='?'){
                int mn=iinf;
                forn(k,4)
                    mn=min(mn,t.h[k]);
                forn(k,4)
                    if(t.h[k]==mn){
                        ++t.h[k];
                        st.pb(t);
                        --t.h[k];
                    }
            }else{
                ++t.h[ind[line[i]]];
                st.pb(t);
            }
        }
        sort(all(st));
        st.erase(unique(all(st)),st.end());
    }
    set<int> res;
    forv(j,st){
        t=st[j];
        int mn=iinf;
        forn(k,4)
            mn=min(mn,t.h[k]);
        forn(k,4)
            if(t.h[k]==mn)
                res.insert(k);
    }
    for(set<int>::iterator it=res.begin();it!=res.end();++it)
        cout<<names[*it]<<endl;

    return 0;
}