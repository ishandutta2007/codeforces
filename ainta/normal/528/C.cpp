#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
bool v[301000];
struct Edge{
    int a, b;
}w[301000];
int n, m, cnt;
void DFS(int a){
    int t, x;
    while(!E[a].empty()){
        t = E[a].back();
        if(v[t]){
            E[a].pop_back();
            continue;
        }
        E[a].pop_back();
        v[t]=true;
        if(w[t].a==a)x=w[t].b;
        else x=w[t].a;
        DFS(x);
        if(cnt&1)printf("%d %d\n",a,x);
        else printf("%d %d\n",x,a);
        cnt++;
    }
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(i);
        E[b].push_back(i);
        w[i].a=a,w[i].b=b;
    }
    a=0;
    for(i=1;i<=n;i++){
        if(E[i].size()%2){
            if(!a)a=i;
            else{
                m++;
                w[m].a=a,w[m].b=i;
                E[a].push_back(m);
                E[i].push_back(m);
                a=0;
            }
        }
    }
    if(m%2==1){
        m++;
        w[m].a=1,w[m].b=1;
        E[1].push_back(m);
        E[1].push_back(m);
    }
    printf("%d\n",m);
    DFS(1);
}