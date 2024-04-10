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

char src[210000];
char line[210000];

vector<int> chpos[26];
int cur[26];

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int qq;
    int n;
    cin>>qq>>n;
    gets(src);
    gets(src);
    forn(i,n)
        chpos[src[i]-'a'].pb(i);
    forn(qqq,qq){
        gets(line);
        forn(i,26)
            cur[i]=0;
        lng r=0;
        int len=strlen(line);
        for(int i=0;line[i];++i){
            ++cur[src[i]-'a'];
            int t=len;
            int c=line[i]-'a';
            if(chpos[c].size()){
                t=iinf;
                if(cur[c]>0)
                    t=min(t,abs(i-chpos[c][cur[c]-1]));
                if(cur[c]<chpos[c].size())
                    t=min(t,abs(chpos[c][cur[c]]-i));
            }
            if(t<0)
                exit(123);
            r+=t;
        }
        cout<<r<<'\n';
    }

    return 0;
}