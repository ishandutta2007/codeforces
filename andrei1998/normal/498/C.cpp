#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
#include <cstring>

using namespace std;

//Dinic's Maxflow Algorithm
//Code by: Andrei1998 (Constantinescu Andrei Costin)

//Complexity
//O(E*V^2)
//O(E*MAXFLOW)

//Don't forget about
//#include <deque>
//#include <bitset>

//Problem specific parameters
#define MAXFLOWNMAX 105
int maxflown,maxflows,maxflowt;

//Actual implementation
int maxflowcap[MAXFLOWNMAX][MAXFLOWNMAX];
int maxflowtata[MAXFLOWNMAX];

bitset<MAXFLOWNMAX> maxflowviz;
deque<int> maxflowcoada;

inline bool maxflowbfs()
{
    maxflowviz&=0;

    maxflowviz[maxflows]=1;
    maxflowtata[maxflows]=0;
    maxflowcoada.push_back(maxflows);

    while(!maxflowcoada.empty()){
        int maxflowy=maxflowcoada.front();

        maxflowcoada.pop_front();

        for(int maxflowi=1;maxflowi<=maxflown;maxflowi++)
            if(maxflowcap[maxflowy][maxflowi])
                if(!maxflowviz[maxflowi]){
                    maxflowviz[maxflowi]=1;
                    maxflowtata[maxflowi]=maxflowy;
                    maxflowcoada.push_back(maxflowi);
                }
    }

    return maxflowviz[maxflowt];
}

inline int maxflow()
{
    if(!maxflown) //For stability issues
        return 0;

    int maxflowflux=0;
    while(maxflowbfs()){
        for(int maxflowi=maxflown;maxflowi>=1;maxflowi--)
            if(maxflowviz[maxflowi] && maxflowcap[maxflowi][maxflowt]){
                int maxflowminim=maxflowcap[maxflowi][maxflowt];
                int maxflownod=maxflowi;

                while(maxflowtata[maxflownod]){
                    maxflowminim=min(maxflowminim,maxflowcap[maxflowtata[maxflownod]][maxflownod]);
                    maxflownod=maxflowtata[maxflownod];
                }

                maxflowflux+=maxflowminim;
                maxflowcap[maxflowi][maxflowt]-=maxflowminim;
                maxflowcap[maxflowt][maxflowi]+=maxflowminim;

                maxflownod=maxflowi;
                while(maxflowtata[maxflownod]){
                    maxflowcap[maxflowtata[maxflownod]][maxflownod]-=maxflowminim;
                    maxflowcap[maxflownod][maxflowtata[maxflownod]]+=maxflowminim;
                    maxflownod=maxflowtata[maxflownod];
                }
            }
    }

    return maxflowflux;
}
//End of Dinic's Maxflow Algorithm

set<int> factors;
inline void desc(int n) {
    for(int i=2;i*i<=n;i++)
        if(n%i==0) {
            factors.insert(i);
            while(n%i==0)
                n/=i;
        }

    if(n>1)
        factors.insert(n);
}

inline int cati(int n,int p) {
    int ans=0;
    while(n%p==0) {
        n/=p;
        ans++;
    }

    return ans;
}

int a[105];
int b[105];

pair<int,int> muchii[105];

int main() {
    int n=0,m=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        cin>>a[i];
        desc(a[i]);
    }

    for(int i=1;i<=m;i++)
        cin>>muchii[i].first>>muchii[i].second;

    int ans=0;

    maxflown=n+2;
    maxflows=n+1;
    maxflowt=n+2;

    for(int i=1;i<=m;i++)
        if(muchii[i].first%2==0)
            swap(muchii[i].first,muchii[i].second);

    set<int>::iterator it;
    for(it=factors.begin();it!=factors.end();it++) {
        memset(maxflowcap,0,sizeof(maxflowcap));

        for(int i=1;i<=n;i++)
            b[i]=cati(a[i],*it);

        for(int i=1;i<=m;i++)
            maxflowcap[muchii[i].first][muchii[i].second]=min(b[muchii[i].first],b[muchii[i].second]);

        for(int i=1;i<=n;i++)
            if(i&1)
                maxflowcap[maxflows][i]=b[i];
            else
                maxflowcap[i][maxflowt]=b[i];

        ans+=maxflow();
    }

    cout<<ans<<'\n';
    return 0;
}