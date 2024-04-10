#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<4096>T[101000];
int n, K, Q;
struct point{
    int num, x;
    bool operator <(const point &p)const{
        return x<p.x;
    }
}w[101000][13];
int main(){
    int i, j;
    scanf("%d%d%d",&n,&K,&Q);
    for(i=0;i<K;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&w[j][i].x);
            w[j][i].num = i;
        }
        for(j=0;j<(1<<K);j++){
            if(j&(1<<i))T[i][j] = 1;
        }
    }
    for(i=1;i<=n;i++)sort(w[i],w[i]+K);
    int cnt = K;
    for(i=0;i<Q;i++){
        int ck, a, b;
        scanf("%d%d%d",&ck,&a,&b);
        if(ck==1 || ck==2){
            a--,b--;
            if(ck==1){
                T[cnt] = T[a]&T[b];
            }
            else{
                T[cnt] = T[a]|T[b];
            }
            cnt++;
        }
        else{
            a--;
            int s = 0;
            for(j=0;j<K;j++){
                s |= (1<<w[b][j].num);
                if(T[a][s]){
                    printf("%d\n",w[b][j].x);
                    break;
                }
            }
        }
    }
}