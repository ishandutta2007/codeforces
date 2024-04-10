#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct A{
    int c, ck, num;
    bool operator<(const A &p)const{
        return c!=p.c?c<p.c:ck>p.ck;
    }
}w[101000];
int n, m, Res[101000][2], UF[101000], TP[101000][2], cnt, pv;
set<int>Set;
vector<int>E[101000];
int main(){
    int i, a, b, j, k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&w[i].c,&w[i].ck);
        w[i].num = i;
    }
    for(i=1;i<=n;i++){
        Set.insert(i);
        UF[i] = i;
        E[i].push_back(i);
    }
    sort(w,w+m);
    for(i=0;i<m;i++){
        if(w[i].ck == 0){
            if(cnt==pv){
                printf("-1\n");
                return 0;
            }
            Res[w[i].num][0] = TP[pv][0], Res[w[i].num][1] = TP[pv][1];
            pv++;
        }
        else{
            a = *Set.begin();
            Set.erase(Set.begin());
            b = *Set.begin();
            Set.erase(Set.begin());
            if(E[a].size() > E[b].size())swap(a,b);
            Set.insert(b);
            Res[w[i].num][0] = a, Res[w[i].num][1] = b;
            UF[a] = b;
            if(cnt<=100000){
                for(j=0;j<E[a].size();j++){
                    for(k=0;k<E[b].size();k++){
                        if(E[a][j]==a &&E[b][k]==b)continue;
                        TP[cnt][0] = E[a][j], TP[cnt][1] = E[b][k];
                        cnt++;
                        if(cnt>100000)break;
                    }
                    if(cnt>100000)break;
                }
            }
            for(j=0;j<E[a].size();j++){
                E[b].push_back(E[a][j]);
            }
            E[a].clear();
        }
    }
    for(i=0;i<m;i++)printf("%d %d\n",Res[i][0],Res[i][1]);
}