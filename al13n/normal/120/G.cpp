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

int n,m;
int A[110][2];
int D[110][110];
string word[110];
vector<string> guessed[110];
int T;

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    //ios_base::sync_with_stdio(false);
    
    cin>>n>>T;
    forn(i,n){
        int a1,a2,b1,b2;
        cin>>a1>>b1>>a2>>b2;
        A[i][0]=a1+b2;
        A[i][1]=a2+b1;
    }
    cin>>m;
    queue<pair<int,int> > qu;
    forn(i,m){
        int c;
        cin>>word[i]>>c;
        qu.push(mp(c,i));
    }
    
    int cur=0;
    while(!qu.empty()){
        int tl=T;
        while(tl&&!qu.empty()){
            int w=qu.front().second;
            int C=qu.front().first;
            qu.pop();
            int t=max(1,C-A[cur][0]-D[cur][w]);
            if(t>tl){
                D[cur][w]+=tl;
                qu.push(mp(C,w));
                break;
            }
            guessed[cur].pb(word[w]);
            tl-=t;
        }
        swap(A[cur][0],A[cur][1]);
        cur=(cur+1)%n;
    }
    
    forn(i,n){
        cout<<guessed[i].size();
        forv(j,guessed[i])
            cout<<' '<<guessed[i][j];
        cout<<'\n';
    }
    
    return 0;
}