#include<stdio.h>
#include<algorithm>
using namespace std;
int oF[110][110];
long long F[110][110], MM;
int n, m, K;
double be = 0.0, ed = 1e10, mid;
bool v[110];
long long DFS(int a, long long f){
    if(a==n)return f;
    int i;
    long long t;
    v[a]=true;
    for(i=n;i>=1;i--){
        if(!v[i]&&F[a][i]){
            t = DFS(i,min(f,F[a][i]));
            if(t){
                F[a][i]-=t;
                F[i][a]+=t;
                return t;
            }
        }
    }
    return 0;
}
int main(){
    int i, j, a,b,c, TT = 100;
    long long tt, ff;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        oF[a][b]+=c;
    }
    while(TT--){
        mid = (be+ed)*0.5;
        MM = -1;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                F[i][j] = (long long)(oF[i][j]/mid);
                if(MM<F[i][j])MM=F[i][j];
            }
        }
        ff = 0;
        if(MM){
            while(1){
                for(i=1;i<=n;i++)v[i] = false;
                tt = DFS(1, MM);
                if(!tt)break;
                ff += tt;
            }
        }
        if(ff<K){
            ed = mid;
        }
        else be = mid;
    }
    printf("%.11lf\n",be*K);
}