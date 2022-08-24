#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n;
vector<pii>Res;
void Go(vector<int>V, int K){
    int i, j, m = V.size();
    for(i=0;i<K;i++){
        for(j=0;j<m;j++){
            if((j>>i)&1)continue;
            Res.push_back({V[j], V[j+(1<<i)]});
        }
    }
}
void Do(vector<int>A, vector<int>B){
    int i;
    for(i=0;i<A.size();i++){
        Res.push_back({A[i],B[i]});
    }
}
int main(){
    scanf("%d",&n);
    int i, cur = 0, j, ck = 0, M = -1;
    vector<int>G[20];
    for(i=15;i>=0;i--){
        if((n>>i)&1){
            vector<int>V;
            for(j=0;j<(1<<i);j++){
                cur++;
                V.push_back(cur);
            }
            G[i]=V;
            Go(V, i);
            if(M==-1)M=i;
            ck++;
        }
    }
    if(ck>2){
        int fi = -1;
        vector<int>cur;
        for(i=0;i<M;i++){
            if(fi == -1){
                if((n>>i)&1){
                    fi=i;
                    vector<int>T;
                    cur = G[i];
                    for(j=0;j<(1<<i);j++){
                        T.push_back(G[M].back());
                        G[M].pop_back();
                    }
                    Do(cur,T);
                    for(auto &t : T)cur.push_back(t);
                }
            }
            else{
                if(!((n>>i)&1)){
                    vector<int>T;
                    for(j=0;j<(1<<i);j++){
                        T.push_back(G[M].back());
                        G[M].pop_back();
                    }
                    Do(cur,T);
                    for(auto &t : T)cur.push_back(t);
                }
                else{
                    vector<int>T = G[i];
                    Do(cur,T);
                    for(auto &t : T)cur.push_back(t);

                }
            }
        }
    }
    printf("%d\n",Res.size());
    for(auto &t : Res)printf("%d %d\n",t.first,t.second);
}