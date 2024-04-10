#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int n, T, TT, Q, P[200010], C[200010], Used[200010];
double Res;
struct point{
    int num;
    long long a, b;
    point(){}
    point(int num_, long long a_, long long b_){a=a_,b=b_,num=num_;}
    bool operator<(const point &p)const{
        return a*p.b!=b*p.a?a*p.b<b*p.a:num<p.num;
    }
};
set<point>S1, S2;
point Curr(int b){
    return point(b, C[b]*P[b], (long long)(Used[b]-1+C[b])*(Used[b]+C[b]));
}
point Next(int b){
    return point(b, C[b]*P[b], (long long)(Used[b]+C[b])*(Used[b]+C[b]+1));
}
void Ins(int b){
    TT++;
    point tp = Next(b);
    Res += (double)tp.a/tp.b;
    S2.erase(tp);
    if(Used[b]) S1.erase(Curr(b));
    Used[b]++;
    S1.insert(Curr(b));
    if(Used[b] != C[b])S2.insert(Next(b));
}
void Del(int b){
    TT--;
    if(C[b]!=Used[b])S2.erase(Next(b));
    point tp = Curr(b);
    Res -= (double)tp.a/tp.b;
    S1.erase(Curr(b));
    Used[b]--;
    if(Used[b])S1.insert(Curr(b));
    S2.insert(Next(b));
}
void DoPush(){
    set<point>::iterator it;
    while(TT<T && !S2.empty()){
        it = S2.end();it--;
        Ins(it->num);
    }
}
void DoSwap(){
    set<point>::iterator it, it2;
    int a, b;
    while(!S1.empty() && !S2.empty()){
        it = S1.begin(), it2 = S2.end();it2--;
        if(!(*it < *it2))break;
        a = it->num, b = it2->num;
        Ins(b);Del(a);
    }
}
double Gap(int p, int c, int u){
    return (double)p*u/(c+u);
}
int main(){
    set<point>::iterator it;
    point tp;
    int i, a, b;
    scanf("%d%d%d",&n,&T,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&P[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&C[i]);
        if(C[i])S2.insert(Next(i));
    }
    DoPush();
    while(Q--){
        scanf("%d%d",&a,&b);
        if(a == 1){
            if(Used[b]!=C[b])S2.erase(Next(b));
            if(Used[b]){
                S1.erase(Curr(b));
                Res -= Gap(P[b],C[b],Used[b]);
                Res += Gap(P[b],C[b]+1,Used[b]-1);
                TT--,Used[b]--;
            }
            C[b]++;
            if(Used[b])S1.insert(Curr(b));
            if(Used[b]!=C[b])S2.insert(Next(b));
            DoPush();
            DoSwap();
            printf("%.11lf\n",Res);
            continue;
        }
        if(a == 2){
            if(Used[b]!=C[b])S2.erase(Next(b));
            if(Used[b]){
                S1.erase(Curr(b));
                Res -= Gap(P[b],C[b],Used[b]);
                Res += Gap(P[b],C[b]-1,Used[b]);
            }
            C[b]--;
            if(Used[b]>C[b]){
                Res -= Gap(P[b],C[b],Used[b]);
                Res += Gap(P[b],C[b],Used[b]-1);
                Used[b]--;TT--;
            }
            if(Used[b])S1.insert(Curr(b));
            if(Used[b]!=C[b])S2.insert(Next(b));
            DoPush();
            DoSwap();
            printf("%.11lf\n",Res);
        }
    }
}