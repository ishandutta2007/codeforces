#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> E[1010000];
int D[1010000];
int P[1010000], S[1010000], w[1010000], SS;
int n, chk, r1, r2, s;
void DFS(int a){
    int i, x;
    vector<int>TP;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        DFS(x);
        if(P[x]){
            TP.push_back(P[x]);
        }
        S[a] += S[x];
    }
    if(TP.size() >= 2){
        r1 = TP[0];
        r2 = TP[1];
    }
    S[a] += w[a];
    if(S[a] == SS / 3){
        P[a] = a;
    }
    if(!TP.empty() && S[a] == SS * 2 / 3 && a != s){
        r1 = TP[0], r2 = a;
    }
    if(!P[a] && !TP.empty())P[a] = TP[0];
}
int main(){
    int i, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&w[i]);
        if(a)E[a].push_back(i);
        else s = i;
        SS += w[i];
    }
    if(SS%3){
        printf("-1\n");
        return 0;
    }
    DFS(s);
    if(!r1)printf("-1\n");
    else printf("%d %d\n",r1,r2);
}