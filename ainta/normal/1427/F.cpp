#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int D[1210][410];
struct AA{
    int ck;
    int pv;
}Path[1210][410];
int w[1210], S[1210], cnt, CK[1210], vis[1210], par[1210];
struct Node{
    int b, e, len;
}U[1210];
vector<int>G[1210];
void Do(int b, int len, int pp){
    //printf("%d %d %d\n",b,len,pp);
    if(len==0)return;
    if(Path[b][len].ck==1){
        cnt++;
        U[cnt] = {b, b+len*3-1,len};
        CK[cnt] = w[b];
        par[cnt]=pp;
        G[pp].push_back(cnt);
        int pv = Path[b][len].pv;
        int L1 = (pv-b)/3;
        int L2 = len-L1-1;
        int cur = cnt;
        Do(b+1, L1, cur);
        Do(pv+1, L2, cur);
    }
    else{
        int pv = Path[b][len].pv;
        int L1 = (pv-b)/3;
        int L2 = len-L1;
        Do(b, L1, pp);
        Do(pv, L2, pp);
    }
}
void Del(int a){
    int z = par[a];
    int i;
    for(i=0;i<G[z].size();i++){
        if(G[z][i]==a){
            swap(G[z][i],G[z][G[z].size()-1]);
            G[z].pop_back();
            return;
        }
    }
}
void Print(int a){
    int b = U[a].b, e = U[a].e, len = U[a].len;
    int pv = Path[b][len].pv;
    printf("%d %d %d\n",b,pv,e);
}
int OK[1210], PP[1210];
int main(){
    int i, a, j;
    scanf("%d",&n);
    for(i=1;i<=3*n;i++){
        scanf("%d",&a);
        w[a]=1;
    }
    for(i=1;i<=6*n;i++){
        S[i]=S[i-1]+w[i];
    }
    for(i=1;i<=6*n;i++)D[i][0]=1;
    for(i=1;i<=2*n;i++){
        int len = i*3;
        for(j=1;j<=6*n-len+1;j++){
            int b = j, e = j+len-1;
            if(S[e]%3 != S[b-1]%3)continue;
            if(w[b]!=w[e])continue;
            if(i==1){
                if(w[j]==w[j+1] && w[j+1]==w[j+2]){
                    D[j][i]=1;
                    Path[j][i]={1,j+1};
                }
                continue;
            }
            for(int k=b+1, l = 0;k<e;k+=3,l++){
                if(D[b+1][l] && D[k+1][i-l-1]){
                    if( (l==0 || w[b+1] != w[b]) && (i-l-1==0 || w[k+1]!=w[b])){
                        D[j][i]=1;
                        Path[j][i]={1,k};
                        break;
                    }
                }
            }
            if(D[j][i])continue;
            for(int k=b+3,l=1;k<e;k+=3,l++){
                if(D[b][l] && D[k][i-l]){
                    D[b][i] = 1;
                    Path[j][i]={2,k};
                }
            }
        }
    }
    OK[0]=1;
    for(i=1;i<=6*n;i++){
        if(!OK[i-1])continue;
        for(j=1;j<=2*n;j++){
            if(D[i][j] && !OK[i+j*3-1]){
                OK[i+j*3-1] = 1;
                PP[i+j*3-1] = i-1;
            }
        }
    }
    int zz = 6*n;
//    for(i=1;i<=6*n;i++)for(j=1;j<=2*n;j++)if(D[i][j])printf("%d %d\n",i,i+j*3-1);
    while(zz){
        Do(PP[zz]+1,(zz-PP[zz])/3,0);
        zz=PP[zz];
    }
    for(i=1;i<=2*n;i++){
        int ck=0;
        for(j=1;j<=cnt;j++){
            if(vis[j])continue;
            if(CK[j]!=i%2)continue;
            if(!G[j].empty())continue;
            if(par[j]==0)continue;
            Print(j);
            Del(j);
            vis[j]=1;
            ck=1;
            break;
        }
        if(!ck){
            for(j=1;j<=cnt;j++){
                if(vis[j])continue;
                if(CK[j]!=i%2)continue;
                if(!G[j].empty())continue;
                Print(j);
                Del(j);
                vis[j]=1;
                break;
            }
 
        }
    }
}