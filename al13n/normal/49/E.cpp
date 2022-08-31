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

char src[110];
vector<pair<char,char> > reps[30];
int n;
int n1,n2;

int canchar[110][110];
int res[60][60];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    gets(src);
    n1=strlen(src);
    gets(src+n1);
    n2=strlen(src+n1);
    n=n1+n2;
    forn(i,n)
        src[i]-='a';
    int m;
    cin>>m;
    forn(i,m){
        string s;
        cin>>s;
        reps[s[0]-'a'].pb(mp(s[3]-'a',s[4]-'a'));
    }

    forn(i,n)
        canchar[i][i+1]=1<<src[i];
    for(int l=2;l<=max(n1,n2);++l){
        forn(i,n-l+1){
            if(i<n1&&i+l>n1)
                continue;
            forn(c,26){
                bool chdone=false;
                forv(j,reps[c]){
                    for(int k=i+1;k<i+l;++k){
                        if((canchar[i][k]&(1<<reps[c][j].first))&&(canchar[k][i+l]&(1<<reps[c][j].second))){
                            canchar[i][i+l]|=1<<c;
                            chdone=true;
                            break;
                        }
                    }
                    if(chdone)
                        break;
                }
            }
        }
    }
    memset(res,-1,sizeof(res));
    res[0][0]=0;
    for(int a=1;a<=n1;++a){
        for(int b=1;b<=n2;++b){
            for(int l1=1;l1<=a;++l1){
                for(int l2=1;l2<=b;++l2){
                    if(!(canchar[a-l1][a]&canchar[n1+b-l2][n1+b]))
                        continue;
                    int t=res[a-l1][b-l2];
                    if(t!=-1&&(res[a][b]==-1||res[a][b]>t+1))
                        res[a][b]=t+1;
                }
            }
        }
    }
    cout<<res[n1][n2];

    return 0;
}