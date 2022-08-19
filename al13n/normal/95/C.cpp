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
#define linf 1000000000000000000LL
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

int drive[1010][1010];
vector<pair<int,int> > gr[1010];
lng dist[1010];
bool done[1010];
int n;

void gendrive(int from,int lim,int cost){
    priority_queue<pair<int,int> > qu;
    forn(i,n)
        dist[i]=linf;
    dist[from]=0;
    qu.push(mp(-0,from));
    while(!qu.empty()){
        int v;
        do{
            v=qu.top().second;
            qu.pop();
        }while(!qu.empty()&&drive[from][v]);
        if(drive[from][v])
            break;
        lng d=dist[v];
        drive[from][v]=cost;
        forv(i,gr[v]){
            int p=gr[v][i].first;
            lng t=d+gr[v][i].second;
            if(t<=lim&&t<dist[p]){
                dist[p]=t;
                qu.push(mp(-t,p));
            }
        }
    }
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int m;
    cin>>n>>m;
    int from,to;
    cin>>from>>to;
    --from,--to;
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        gr[a].pb(mp(b,c));
        gr[b].pb(mp(a,c));
    }

    forn(i,n){
        int l,c;
        cin>>l>>c;
        gendrive(i,l,c);
    }

    forn(i,n)
        dist[i]=linf;
    dist[from]=0;
    while(!done[to]){
        lng mind=linf;
        int v=-1;
        forn(i,n)
            if(!done[i]&&dist[i]<mind)
                mind=dist[i],
                v=i;
        if(v==-1)
            break;
        done[v]=true;
        lng d=dist[v];
        forn(i,n)
            if(drive[v][i])
                dist[i]=min(dist[i],d+drive[v][i]);
    }

    if(dist[to]==linf)
        cout<<-1;
    else
        cout<<dist[to];

    return 0;
}