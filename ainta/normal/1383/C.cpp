#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[201000], q[201000];
int n, w[25][25], SCC[25], Z[25][25], dd[25][25], P[25][25], M[25], D[1<<21];
int Do(vector<int>T){
    int m = T.size(), i, j;
    if(m==1){
        return 0;
    }
    /*puts("!");
    for(auto &t : T)printf("%d ",t);
    puts("");*/
    for(i=0;i<m;i++)M[i]=0;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            P[i][j]=w[T[i]][T[j]];
            if(P[i][j])M[j] |=(1<<i);
        }
    }
    //for(i=0;i<m;i++)printf("%d ",M[i]);
    //puts("");
    for(i=0;i<(1<<m);i++)D[i]=1e9;
    D[0]=0;
    for(i=0;i<(1<<m);i++){
        int c=0;
        for(j=0;j<m;j++){
            if((i>>j)&1)c++;
        }
        for(j=0;j<m;j++){
            if((i>>j)&1)continue;
            int t = D[i];
            if((M[j]&i)!=M[j])t = c+1;
            D[i|(1<<j)]=min(D[i|(1<<j)], t);
        }
    }
    return m+D[(1<<m)-1]-1;
}
void Solve(){
    int i, j, k;
    scanf("%d",&n);
    scanf("%s",p);
    scanf("%s",q);
    for(i=0;i<25;i++)for(j=0;j<25;j++)w[i][j]=0;
    for(i=0;i<n;i++){
        if(p[i]!=q[i]){
            w[p[i]-'a'][q[i]-'a']=1;
        }
    }
    n = 20;
    for(i=0;i<n;i++)for(j=0;j<n;j++)dd[i][j]=w[i][j];
    for(i=0;i<n;i++)for(j=0;j<n;j++)w[i][j]|=w[j][i];
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(w[i][k]&&w[k][j])w[i][j]=1;
            }
        }
    }
    int cnt=0;
    for(i=0;i<n;i++)SCC[i]=0;
    for(i=0;i<n;i++){
        if(SCC[i])continue;
        cnt++;
        for(j=0;j<n;j++){
            if(i==j || (w[i][j]&&w[j][i]))SCC[j]=cnt;
        }
    }
    //for(i=0;i<n;i++)printf("%d ",SCC[i]);
    //puts("");

    int res=0;

    for(i=0;i<n;i++)for(j=0;j<n;j++)w[i][j]=dd[i][j];

    for(i=1;i<=cnt;i++){
        vector<int>T;
        for(j=0;j<n;j++){
            if(SCC[j]==i)T.push_back(j);
        }
        res += Do(T);
    }
    printf("%d\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}