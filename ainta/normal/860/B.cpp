#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct point{
    char p[10];
    bool operator<(const point &q)const{
        return strcmp(p, q.p) < 0;
    }
    int num, pv;
}w[641000];
char Q[70100][10];
int MM[99999], R[99999], n, cnt;
char q[10];
int main(){
    int i, j, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",q);
        for(j=0;j<9;j++){
            Q[i][j]=q[j];
            for(k=j;k<9;k++){
                w[cnt].p[k-j] = q[k];
            }
            w[cnt].num = i, w[cnt].pv = j;
            cnt++;
        }
    }
    sort(w,w+cnt);
    for(i=1;i<=n;i++)MM[i] = 1e9;
    for(i=0;i<cnt;i++){
        int be = -1, ed = -1;
        for(j=i-1;j>=0;j--)if(w[i].num!=w[j].num){
            be = j;
            break;
        }
        for(j=i+1;j<cnt;j++)if(w[i].num!=w[j].num){
            ed=j;
            break;
        }
        if(be!=-1 && strcmp(w[i].p, w[be].p)==0)continue;
        if(ed!=-1 && strcmp(w[i].p, w[ed].p)==0)continue;
        int ck = 0;
        for(j=0;j<w[i].p[j];j++){
            if(be==-1 || w[be].p[j]!=w[i].p[j])ck |= 1;
            if(ed==-1 || w[ed].p[j]!=w[i].p[j])ck |= 2;
            if(ck==3)break;
        }
        if(w[i].p[j] && MM[w[i].num] > j+1){
            MM[w[i].num] = j+1;
            R[w[i].num] = w[i].pv;
        }
    }
    for(i=1;i<=n;i++){
        for(j=R[i];j<R[i]+MM[i];j++)printf("%c", Q[i][j]);
        printf("\n");
    }
}