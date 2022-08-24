#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<vector>
using namespace std;
int n;
struct point{
    int a, b;
}w[501000];
vector<int>E[1100000], Num[1100000], Save, G[1100000], Ans;
int vis[1100000];
void Add_Edge(int a, int b, int c){
    if(a==b){
        G[a].push_back(c*2);
        return;
    }
    E[a].push_back(b);
    E[b].push_back(a);
    Num[a].push_back(c*2);
    Num[b].push_back(c*2+1);
}
void DFS(int a){
    while(!E[a].empty()){
        int x = E[a].back();
        int num = Num[a].back();
        E[a].pop_back();
        Num[a].pop_back();
        if(vis[num/2]){
            continue;
        }
        vis[num/2] = 1;
        DFS(x);
        Save.push_back(num);
    }
    while(!G[a].empty()){
        Save.push_back(G[a].back());
        G[a].pop_back();
    }
}
bool Pos(int mid){
    int i, Mod = (1<<mid);
    for(i=0;i<Mod;i++){
        E[i].clear();
        G[i].clear();
        Num[i].clear();
    }
    for(i=1;i<=n;i++){
        vis[i]=0;
        Add_Edge(w[i].a%Mod, w[i].b%Mod, i);
    }
    int rt=0;
    Save.clear();
    for(i=0;i<Mod;i++){
        if(E[i].size()%2){
            return false;
        }
        if(E[i].size() || G[i].size())rt=i;
    }
    DFS(rt);
    if(Save.size()!=n)return false;
    Ans=Save;
    return true;
}
int main(){
    int i, b=0,e=20,r=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].a,&w[i].b);
    }
    while(b<=e){
        int mid = (b+e)>>1;
        if(Pos(mid)){
            r=mid;
            b=mid+1;
        }
        else e=mid-1;
    }
    printf("%d\n",r);
    for(auto &t : Ans){
        printf("%d %d ",(t^1)-1,t-1);
    }
}