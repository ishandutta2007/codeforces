#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int Nxt[201000];
vector<int>E[201000];
int n, Mod = 1000000007, v[201000], s, res = 1, c, chk[201000], cc;
void DFS(int a){
    s += E[a].size();
    if(chk[a]) cc = 1;
    c++;
    v[a] = 1;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
}
int main(){
    int i, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        Nxt[a] = b;
        if(a==b)chk[a] = 1;
        E[b].push_back(a);
        E[a].push_back(b);
    }
    for(i=1;i<=n+n;i++){
        if(!v[i]){
            s = c = cc = 0;
            DFS(i);
            if(s == c * 2){
                if(!cc)res = res * 2 % Mod;
            }
            else{
                res = 1ll * res * c%Mod;
            }
        }
    }
    printf("%d\n",res);
}