#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
struct Trie{
    int ch[26], par;
}w[601000];
int C[301000], Res[301000];
vector<pii>TP;
int n, rr, cnt;
void Do(int a, int b){
    int i;
    for(i=0;i<26;i++){
        if(!w[b].ch[i])continue;
        if(!w[a].ch[i]){
            w[a].ch[i] = ++cnt;
            TP.push_back(pii(a,i));
        }
        else rr++;
        Do(w[a].ch[i], w[b].ch[i]);
    }
}
void DFS(int a, int dep){
    int i, Mx = 0, pv = -1, x, vv;
    C[a] = 1;
    for(i=0;i<26;i++){
        if(w[a].ch[i]){
            DFS(w[a].ch[i], dep + 1);
            C[a] += C[w[a].ch[i]];
            if(Mx < C[w[a].ch[i]]){
                Mx = C[w[a].ch[i]], pv = w[a].ch[i];
            }
        }
    }
    if(pv==-1)return;
    vv = pv;
    rr = 1;
    cnt = n;
    for(i=0;i<26;i++){
        x = w[a].ch[i];
        if(!x)continue;
        if(x == pv)continue;
        rr++;
        Do(pv, x);
    }
    Res[dep] += rr;
    for(i=0;i<TP.size();i++){
        w[TP[i].first].ch[TP[i].second] = 0;
    }
    TP.clear();
}
int main(){
    int i, a, b, Mx = -1;
    char pp[3];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d%s",&a,&b,pp);
        w[a].ch[pp[0]-'a'] = b;
        w[b].par = a;
    }
    DFS(1, 1);
    for(i=1;i<=n;i++){
        if(Mx < Res[i])Mx = Res[i], a = i;
    }
    printf("%d\n%d\n",n-Mx,a);
}