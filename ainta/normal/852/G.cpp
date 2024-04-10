#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Trie{
    int ch[5], ter;
}T[5010000];
int cnt;
void Ins(int nd, char *key){
    if(!(*key)){
        T[nd].ter++;
        return;
    }
    int t = (*key) - 'a';
    if(!T[nd].ch[t]){
        T[nd].ch[t] = ++cnt;
    }
    Ins(T[nd].ch[t], key + 1);
}
int v[5010000];
int main(){
    char p[100];
    int n, m, i, j, k, ii;
    scanf("%d%d",&n,&m);
    cnt = 1;
    for(i=1;i<=n;i++){
        scanf("%s",p);
        Ins(1, p);
    }
    for(i=0;i<m;i++){
        scanf("%s",p);
        vector<int>S, TP;
        S.push_back(1);
        for(j=0;p[j];j++){
            TP.clear();
            for(k=0;k<S.size();k++){
                int x = S[k], t;
                if(p[j]=='?'){
                    for(ii=0;ii<5;ii++){
                        t = T[x].ch[ii];
                        if(t && !v[t]){
                            v[t] = 1;
                            TP.push_back(t);
                        }
                    }
                    if(!v[x]){
                        v[x] = 1;
                        TP.push_back(x);
                    }
                }
                else{
                    t = T[x].ch[p[j]-'a'];
                    if(t && !v[t]){
                        v[t] = 1;
                        TP.push_back(t);
                    }
                }
            }
            S.resize(TP.size());;
            for(k=0;k<TP.size();k++){
                v[TP[k]] = 0;
                S[k] = TP[k];
            }
        }
        int res = 0;
        for(j=0;j<S.size();j++){
            res += T[S[j]].ter;
        }
        printf("%d\n",res);
    }
}