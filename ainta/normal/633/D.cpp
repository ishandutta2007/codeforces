#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int w[1010], n, Next[1010][1010], cnt, G[1010], Res = 2, C[1010];
bool v[1010][1010];
map<int,int>Map;
int main(){
    int i, j, t, x, y, c;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(!Map[w[i]]){
            Map[w[i]] = ++cnt;
            G[cnt] = w[i];
        }
        w[i] = Map[w[i]];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            t = Map[G[w[i]] + G[w[j]]];
            if(t)Next[w[i]][w[j]] = t;
        }
    }
    for(i=1;i<=n;i++)C[w[i]]++;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)continue;
            if(v[w[i]][w[j]])continue;
            v[w[i]][w[j]]=true;
            C[w[i]]--,C[w[j]]--;
            x = w[i], y = w[j];
            c = 2;
            while(Next[x][y] && C[Next[x][y]]){
                c++;
                t = Next[x][y];
                C[t]--;
                x = y; y = t;
            }
            if(Res<c)Res=c;
            C[w[i]]++,C[w[j]]++;
            c-=2;
            x = w[i], y = w[j];
            while(c){
                t = Next[x][y];
                C[t]++;
                x=y;y=t;c--;
            }
        }
    }
    printf("%d\n",Res);
}