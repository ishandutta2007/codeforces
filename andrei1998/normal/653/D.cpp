#include <iostream>
#include <cmath>
#include <iomanip>
#include <queue>
#include <bitset>

#define lint long long int
using namespace std;

//Dinic's Maxflow Algorithm
//Don't forget about
//#include <queue>
//#include <bitset>

//Problem specific parameters
#define MAXFLOWNMAX 55
int maxflown,maxflows,maxflowt;

//Actual implementation
lint maxflowcap[MAXFLOWNMAX][MAXFLOWNMAX];
lint maxflowcap_old[55][55];
int maxflowtata[MAXFLOWNMAX];

bitset<MAXFLOWNMAX> maxflowviz;
queue<int> maxflowcoada;

bool maxflowbfs()
{
    maxflowviz&=0;

    maxflowviz[maxflows]=1;
    maxflowtata[maxflows]=0;
    maxflowcoada.push(maxflows);

    while(!maxflowcoada.empty()){
        int maxflowy=maxflowcoada.front();

        maxflowcoada.pop();

        for(int maxflowi=1;maxflowi<=maxflown;maxflowi++)
            if(maxflowcap[maxflowy][maxflowi])
                if(!maxflowviz[maxflowi]){
                    maxflowviz[maxflowi]=1;
                    maxflowtata[maxflowi]=maxflowy;
                    maxflowcoada.push(maxflowi);
                }
    }

    return maxflowviz[maxflowt];
}

inline lint maxflow(double w)
{
    for (int i = 1; i <= maxflown; ++ i)
        for (int j = 1; j <= maxflown; ++ j)
            maxflowcap[i][j] = floor(maxflowcap_old[i][j] / w + 1e-10);

    lint maxflowflux=0;
    while(maxflowbfs()){
        for(int maxflowi=1;maxflowi<=maxflown;maxflowi++)
            if(maxflowviz[maxflowi] && maxflowcap[maxflowi][maxflowt]){
                lint maxflowminim=maxflowcap[maxflowi][maxflowt];
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

//Test Code
int main()
{
    int x;
    int m=0;
    cin>>maxflown>>m >> x;

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        maxflowcap_old[a][b]=c;
    }

    maxflows=1,maxflowt=maxflown;

    double st = 0;
    double dr = 1000005;
    double mid;
    double ans = 0;

    for (int steps = 0; steps < 80; ++ steps) {
        mid = (st + dr) * 0.5;
        if (maxflow(mid) >= x) {
            ans = mid;
            st = mid;
        }
        else
            dr = mid;
    }

    cout << fixed << setprecision(10) << ans * x << '\n';
    return 0;
}