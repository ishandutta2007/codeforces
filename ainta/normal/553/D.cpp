#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
struct Heap{
    int num;
    long long a, b;
    bool operator<(const Heap &p)const{
        return b*p.a>p.b*a;
    }
}H[401000];
int n,m,K, top, deg[101000], deg2[101000], TP[101000], cc, cnt;
bool v[101000];
void Push(int num, int a,int b){
    Heap tp;
    tp.num=num, tp.a=a,tp.b=b;
    H[top++]=tp;
    push_heap(H,H+top);
}
void Do(){
    Heap tp;
    int a;
    int i;
    tp = H[0];
    a=tp.num;
    pop_heap(H,H+top);
    top--;
    if(v[a])return;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]]){
            deg2[E[a][i]]--;
            Push(E[a][i],deg[E[a][i]],deg2[E[a][i]]);
        }
    }
    v[a]=true;
    TP[cc++]=a;
    cnt++;
}
int main(){
    int i, a, b;
    scanf("%d%d%d",&n,&m,&K);
    cnt = K;
    for(i=1;i<=K;i++){
        scanf("%d",&a);
        v[a]=true;
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        deg[a]++,deg[b]++;
        if(!v[a]&&!v[b]){
            deg2[a]++,deg2[b]++;
        }
    }
    for(i=1;i<=n;i++){
        if(!v[i]){
            Push(i, deg[i],deg2[i]);
        }
    }
    Heap tp;
    while(1){
        tp=H[0];
        cc=0;
        Do();
        while(tp < H[0] && cnt < n){
            Do();
        }
        if(cnt==n)break;
    }
    printf("%d\n",cc);
    for(i=0;i<cc;i++)printf("%d\n",TP[i]);
}