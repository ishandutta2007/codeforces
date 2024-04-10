#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<int>E[101000], L[101000], Ch[101000];
int n, C[101000], D[101000], cnt, Num[101000];
int S[101000];
map<vector<int>,int>Map;
void DFS(int a, int pp){
    int i;
    C[a] = 1;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            DFS(E[a][i], a);
            C[a] += C[E[a][i]];
        }
    }
}
void DFS2(int a, int pp){
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            Ch[a].push_back(E[a][i]);
            DFS2(E[a][i], a);
            D[a] = max(D[a], D[E[a][i]] + 1);
        }
    }
}
void Ins(int a){
    vector<int>TP;
    int i;
    for(i=0;i<Ch[a].size();i++){
        TP.push_back(Num[Ch[a][i]]);
    }
    if(!TP.empty())sort(TP.begin(),TP.end());
    if(!Map[TP]) {
        Map[TP] = ++cnt;
        Num[a] = cnt;
    }
    else Num[a] = Map[TP];
}
int R, res, Ans;
void Do(int a, int c){
    S[Num[a]]--;
    if(!S[Num[a]])R--;
    if(res < R+c){
        res=R+c;
        Ans = a;
    }
    int i;
    for(i=0;i<Ch[a].size();i++){
        Do(Ch[a][i], c+1);
    }
    if(!S[Num[a]])R++;
    S[Num[a]]++;
}
int main(){
    int i, a, b, j;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1, 0);
    int Mn = n+1, x = -1;
    for(i=1;i<=n;i++){
        if(C[i]*2 > n && Mn > C[i])Mn = C[i], x = i;
    }
    DFS2(x, 0);
    for(i=1;i<=n;i++)L[D[i]].push_back(i);
    for(i=0;i<n;i++){
        Map.clear();
        for(j=0;j<L[i].size();j++){
            Ins(L[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        S[Num[i]]++;
    }
    R  = cnt;
    res = 0;
    Do(x, 1);
    printf("%d\n",Ans);
}