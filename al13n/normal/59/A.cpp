#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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
#include <limits>
#include <complex>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forv(i,v) forn(i,(int)v.size())
#define time asdtime
#define pb push_back
#define lng long long
#define mp make_pair
#define iinf 1000000000
#define prev asdprev
#define next asdnext
#define all(v) v.begin(),v.end()
#define SQ(a) ((a)*(a))
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define ABS(a) ((a)<0?-(a):(a))
#define PI 3.1415926535897932384626433832795



int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    string s;
    cin>>s;
    int c=0;
    forn(i,s.length())
        if(s[i]>='a'&&s[i]<='z')
            ++c;
    if(c>=s.length()-c){
        forn(i,s.length())
            if(s[i]>='A'&&s[i]<='Z')
                s[i]+='a'-'A';
    }else{
        forn(i,s.length())
            if(s[i]>='a'&&s[i]<='z')
                s[i]+='A'-'a';
    }
    cout<<s;

    return 0;
}