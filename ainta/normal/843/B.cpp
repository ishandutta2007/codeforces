#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n, st, x, nxt, val, cnt;
//int VV[6]={0,97,58,16,81,79}, NN[6] = {0,-1,5,2,1,4};
struct point{
    int num, Val, Nxt;
    bool operator<(const point &p)const{
        return Val < p.Val;
    }
}w[3010];
void Query(int a){
    printf("? %d\n",a);
    fflush(stdout);
    scanf("%d%d",&val,&nxt);
  //  val = VV[a], nxt = NN[a];
    w[++cnt] = {a, val, nxt};
}
void Print(int a){
    printf("! %d\n",a);
    fflush(stdout);
}
int main(){
    srand(2029);
    int i;
    scanf("%d%d%d",&n,&st,&x);
    for(i=1;i<=1000;i++){
        int a = (rand() * 100 + rand())%n+1;
        Query(a);
    }
    Query(st);
    sort(w+1,w+cnt+1);
    for(i=1;i<=cnt;i++){
        if(w[i].Val > x)break;
    }
    if(i==1){
        Print(w[1].Val);
        return 0;
    }
    int tp = w[i-1].num;
    while(tp!=-1){
        Query(tp);
        int t = w[cnt].Val;
        if(t >= x){
            Print(t);
            return 0;
        }
        tp = w[cnt].Nxt;
    }
    Print(-1);
    return 0;
}