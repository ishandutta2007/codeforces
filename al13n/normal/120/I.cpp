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
#define eps 1e-8
#define y1 asdy1
#define y0 asdy0
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define dinf = 1e200

int bitcnt(int a){
    int r=0;
    while(a){
        r+=a&1;
        a>>=1;
    }
    return r;
}
const int digit[]={1+32+64+4+16+8, 32+64, 1+32+2+16+4, 1+32+2+64+4, 8+2+32+64, 1+8+2+64+4, 1+8+2+16+64+4, 1+32+64, 127, 127-16};
int get(char a,char b){
    return bitcnt(digit[a-'0']&digit[b-'0']);
}

char str[210000];
int n;

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    //ios_base::sync_with_stdio(false);
    
    gets(str);
    n=strlen(str)/2;
    
    int luck=0;
    forn(i,n)
        luck+=get(str[i],str[i+n]);
    
    int luck0=luck;
    
    int p=n*2;
    while(true){
        --p;
        if(p<0){
            cout<<-1;
            return 0;
        }
        if(p>=n)
            luck-=get(str[p-n],str[p]);
        else
            luck-=get(str[p],str[p]);
        char c;
        int l=-1;
        for(c=str[p]+1;c<='9';++c){
            int d;
            if(p>=n)
                d=get(str[p-n],c);
            else
                d=get(c,c);
            l=luck+d;
            if(l>luck0)
                break;
        }
        if(l>luck0){
            str[p]=c;
            luck=l;
            ++p;
            break;
        }
        if(p>=n)
            luck+=get(str[p-n],str[p-n]);
        else
            luck+=7;
    }
    while(p<n*2){
        int d;
        char c;
        for(c='0';;++c){
            if(c>'9')
                exit(123);
            if(p>=n)
                d=get(str[p-n],c)-get(str[p-n],str[p-n]);
            else
                d=get(c,c)-7;
            if(luck+d>luck0)
                break;
        }
        luck+=d;
        str[p]=c;
        ++p;
    }
    
    printf("%s",str);
    
    return 0;
}