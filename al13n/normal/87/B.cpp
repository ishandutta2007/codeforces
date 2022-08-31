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
#ifdef __ASD__
#include <windows.h>
#endif
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
#define left asdleft
#define prev asdprev
#define eps 1e-10
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

map<string,int> defs;

int doit(string s){
    int i=0;
    int v1=0,v2=0;
    while(s[i]=='&'){
        ++v1;
        ++i;
    }
    i=s.length()-1;
    while(s[i]=='*')
        ++v2,--i;
    s=s.substr(v1,i-v1+1);

    if(!defs.count(s))
        return -1;
    if(defs[s]==-1)
        return -1;
    return max(-1,defs[s]+v2-v1);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    defs["void"]=0;
    defs["errtype"]=-1;
    forn(i,n){
        string a,b,c;
        cin>>a>>b;
        if(a=="typedef"){
            cin>>c;
            defs[c]=doit(b);
        }else if(a=="typeof"){
            int r=doit(b);
            if(r==-1)
                cout<<"errtype";
            else{
                cout<<"void";
                forn(j,r)
                    cout<<'*';
            }
            cout<<'\n';
        }else
            exit(123);
    }

    return 0;
}