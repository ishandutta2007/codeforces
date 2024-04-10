#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, D[201000], first = 0;
vector<int>E[201000];
void DFS(int a, int pp){
    int i;
    vector<int>TP;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp)continue;
        DFS(E[a][i],a);
        if(D[E[a][i]]==-1){
            D[a]=-1;
            return;
        }
        TP.push_back(D[E[a][i]]+1);
    }
    if(TP.empty()){
        D[a]=0;
        return;
    }
    sort(TP.begin(),TP.end());
    int ck = 0;
    for(i=0;i<TP.size()-1;i++){
        if(TP[i]!=TP[i+1]){
            ck++;
        }
    }
    if(pp!=0){
        if(ck){
            D[a]=-1;
            first = a;
            return;
        }
        D[a] = TP[0];
    }
    if(pp==0){
        if(ck>1){
            D[a]=-1;
            first = a;
            return;
        }
        if(ck==1){
            D[a] = TP[0]+TP[TP.size()-1];
        }
        else D[a] = TP[0];
    }
}
int main(){
    int i, a, b, g = 0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    a = -1;
    for(i=1;i<=n;i++){
        if(E[i].size()>=3)a = i;
    }
    if(a==-1){
        a=n-1;
        while(a%2==0)a/=2;
        printf("%d\n",a);
        return 0;
    }
    DFS(a,0);
    if(D[a]!=-1){
        g = D[a];
    }
    else{
        DFS(first, 0);
        if(D[first] == -1){
            printf("-1\n");
            return 0;
        }
        g = D[first];
    }
    while(g%2==0)g/=2;
    printf("%d\n",g);
}