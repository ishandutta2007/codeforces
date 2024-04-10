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

char src[10000];
bool dp[1100][1100];

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    gets(src);
    gets(src);
    for(int i=1;i<=n;++i)
        dp[n-1][i]=true;
    for(int i=n-2;i>=0;--i){
        for(int j=1;j<=n;++j){
            if(src[i]=='L')
                dp[i][j]=dp[i+1][j-1];
            else if(src[i]=='R')
                dp[i][j]=true;
            else if(src[i]=='=')
                dp[i][j]=dp[i+1][j];
            else
                exit(123);
        }
    }
    int v=0;
    for(int i=0;i<n;++i){
        for(int j=1;;++j){
            if((!i||src[i-1]=='R'&&j>v||src[i-1]=='L'&&j<v||src[i-1]=='='&&j==v)&&dp[i][j]){
                v=j;
                cout<<v<<' ';
                break;
            }
        }
    }

    return 0;
}