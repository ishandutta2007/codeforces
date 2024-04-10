#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct AA{
    int x, c, p;
    bool operator<(const AA &q)const{
        return p<q.p;
    }
}w[10100], P[10100];
int m, n, mm, QQ, Q[5010], D[5010], head, tail, cnt;
vector<int>E[5010];
void BFS(int a){
    int i, x;
    head=tail=0;
    for(i=1;i<=n;i++)D[i]=-1;
    D[a]=0,Q[++tail]=a;
    while(head<tail){
        x = Q[++head];
        for(i=0;i<E[x].size();i++){
            if(D[E[x][i]] == -1){
                Q[++tail] = E[x][i];
                D[E[x][i]] = D[x]+1;
            }
        }
    }
}
long long Get(int d, int cc){
    int i;
    long long r = 0;
    for(i=1;i<=cnt;i++){
        if(D[P[i].x] > d)continue;
        if(P[i].c >= cc){
            r += 1ll*P[i].p*cc;
            return r;
        }
        r += 1ll*P[i].p*P[i].c;
        cc-=P[i].c;
    }
    if(cc)return -1;
    return r;
}
int main(){
    int i, a, c, p, b;
    scanf("%d%d",&n,&mm);
    while(mm--){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&w[i].x,&w[i].c,&w[i].p);
    }
    scanf("%d",&QQ);
    while(QQ--){
        scanf("%d%d%d",&a,&c,&p);
        BFS(a);
        cnt = 0;
        int bb = 0, ee = 0, r = -1, mid;
        for(i=1;i<=m;i++){
            if(D[w[i].x] == -1)continue;
            cnt++;
            ee = max(ee, D[w[i].x]);
            P[cnt].x = w[i].x;
            P[cnt].c = w[i].c;
            P[cnt].p = w[i].p;
        }
        sort(P+1,P+cnt+1);
        while(bb<=ee){
            mid = (bb+ee)>>1;
            long long t = Get(mid,c);
            if(t==-1 || t>p){
                bb = mid + 1;
            }
            else{
                r = mid;
                ee = mid - 1;
            }
        }
        printf("%d\n",r);
    }
}