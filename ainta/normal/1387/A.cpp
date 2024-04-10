#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define N_ 201000
using namespace std;
struct Edge{
    int b, e, c;
};
vector<Edge>E[N_];
vector<int>T;
int n, m, vis[N_], A[N_], B[N_];
double tp, R[N_];
void DFS(int a, int CA, int CB){
    vis[a]=1;
    T.push_back(a);
    A[a]=CA,B[a]=CB;
    for(auto &t : E[a]){
        if(!vis[t.e]){
            DFS(t.e, -CA, t.c-CB);
        }
    }
    for(auto &t : E[a]){
        int x = t.e;
        int aa = A[a]+A[x], bb = B[a]+B[x];
        int cc = t.c - bb;
        if(aa==0){
            if(cc!=0)tp = -1;
        }
        else{
            tp = (double)cc/aa;
        }
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back({a,b,c});
        E[b].push_back({b,a,c});
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            tp = 1e9;
            T.clear();
            DFS(i,1,0);
            long long sa=0,sb=0;
            if(tp<8e8){
                for(auto &t : T){
                    R[t]=A[t]*tp+B[t];
                }
                for(auto &t : T){
                    for(auto &e : E[t]){
                        if(fabs(R[t]+R[e.e]-e.c) > 1e-6){
                            puts("NO");
                            return 0;
                        }
                    }
                }
            }
            else{
                vector<int>Z;
                for(auto &t : T){
                    if(A[t]==1)Z.push_back(-B[t]);
                    else Z.push_back(B[t]);
                }
                sort(Z.begin(),Z.end());
                int oo = Z[Z.size()/2];
                for(auto &t : T){
                    R[t] = A[t]*oo+B[t];
                }
            }
        }
    }
    puts("YES");
    for(i=1;i<=n;i++)printf("%.10f ",R[i]);
}