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
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

char s[110000];
int n;

void anslong(int l){
    forn(i,l/2)
        s[i]='4',
        s[i+l/2]='7';
    printf("%s",s);
    exit(0);
}

void tryend(int p,int c4,int c7){
    if(c4+c7!=p)
        exit(321);
    if(c4>n/2||c7>n/2)
        return;
    while(p<n){
        if(c4<n/2){
            ++c4;
            s[p]='4';
        }else{
            ++c7;
            s[p]='7';
        }
        ++p;
    }
    printf("%s",s);
    exit(0);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    gets(s);
    n=strlen(s);

    if(n%2)
        anslong(n+1);

    bool can=true;
    forn(i,n){
        char c='7';
        if(i>=n/2)
            c='4';
        if(s[i]<c)
            break;
        if(s[i]>c)
            anslong(n+2);
    }

    int c4=0,c7=0,p=n;

    forn(i,n)
        if(s[i]=='4')
            ++c4;
        else if(s[i]=='7')
            ++c7;
        else{
            p=i;
            break;
        }

    if(p==n)
        tryend(p,c4,c7);

    for(int i=p;i>=0;--i){
        if(i<n){
            char c=s[i];
            if(c<'4'){
                s[i]='4';
                tryend(i+1,c4+1,c7);
            }
            if(c<'7'){
                s[i]='7';
                tryend(i+1,c4,c7+1);
            }
        }

        if(i)
            if(s[i-1]=='4')
                --c4;
            else if(s[i-1]=='7')
                --c7;
    }
    
    return 0;
}