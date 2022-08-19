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
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define left asdleft

bool can[210][60];
int n;
int cdir;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    int a,b;
    cin>>n>>a>>b;
    --a;--b;
    can[0][a]=true;
    string s;
    cin>>s;
    cin>>s;
    if(s=="head")
        cdir=-1;
    else if(s=="tail")
        cdir=1;
    else
        exit(123);
    int cpos=b;
    cin>>s;

    forn(i,(int)s.length()){
        bool moving=s[i]=='0';
        bool any=false;
        int ncpos;
        if(cpos+cdir>=n||cpos+cdir<0)
            cdir*=-1;
        ncpos=cpos+cdir;
        forn(j,n){
            if(!can[i][j])
                continue;
            any=true;
            if(moving){
                for(int t=j-1;t<=j+1;++t){
                    if(t<0||t>=n||t==cpos||t==ncpos)
                        continue;
                    can[i+1][t]=true;
                }
            }else{
                forn(t,n){
                    if(t==ncpos)
                        continue;
                    can[i+1][t]=true;
                }
            }
        }
        if(!any){
            if(!i)
                exit(321);
            cout<<"Controller "<<i;
            return 0;
        }
        cpos=ncpos;
    }
    cout<<"Stowaway";

    return 0;
}