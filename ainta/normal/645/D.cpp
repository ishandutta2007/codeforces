#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
int be, ed, mid, n, m, w[101000][2], Deg[101000], res = -1, Q[101000], h, t, ck, x;
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&w[i][0],&w[i][1]);
    }
    be=0,ed=m;
    while(be<=ed){
        mid = (be+ed)>>1;
        for(i=1;i<=n;i++){
            E[i].clear();
            Deg[i]=0;
        }
        for(i=1;i<=mid;i++){
            E[w[i][0]].push_back(w[i][1]);
            Deg[w[i][1]]++;
        }
        h=t=0;
        for(i=1;i<=n;i++)if(!Deg[i])Q[++t] = i;
        ck = 0;
        while(h<t){
            if(t!=h+1)ck=1;
            x = Q[++h];
            for(i=0;i<E[x].size();i++){
                Deg[E[x][i]]--;
                if(!Deg[E[x][i]])Q[++t] = E[x][i];
            }
        }
        if(ck==0){
            res = mid;
            ed = mid - 1;
        }
        else be = mid+1;
    }
    printf("%d\n",res);
}