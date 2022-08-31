#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Deg[201000], Q[201000], v1[201000], v2[201000];
char p[201000];
vector<int>E[201000], F[201000];
void DFS1(int a){
    v1[a]=1;
    for(auto &x : E[a]){
        if(!v1[x])DFS1(x);
    }
}
void DFS2(int a){
    v2[a]=1;
    for(auto &x : F[a]){
        if(!v2[x])DFS2(x);
    }
}
int main(){
    int i, a, b, head=0,tail=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        F[b].push_back(a);
        Deg[b]++;
    }
    for(i=1;i<=n;i++){
        if(!Deg[i])Q[++tail]=i;
    }
    while(head < tail){
        int x = Q[++head];
        for(auto &y : E[x]){
            Deg[y]--;
            if(!Deg[y])Q[++tail]=y;
        }
    }
    if(tail!=n){
        puts("-1");
        return 0;
    }
    int r=0;
    for(i=1;i<=n;i++){
        if(!v1[i] && !v2[i]){
            p[i-1]='A';
            r++;
        }
        else p[i-1]='E';
        if(!v1[i]){
            DFS1(i);
        }
        if(!v2[i]){
            DFS2(i);
        }
    }
    printf("%d\n",r);
    printf("%s\n",p);
}