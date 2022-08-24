#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n, m, w[101000], tp[101000], v[101000], B[320], cnt, P[101000];
long long Res[101000];
struct point{
    int ck, a, b;
}Q[101000];
set<int>Set[101000];
int OC;
long long BIT[101000];
struct QQ{
    int b, e, num;
    bool operator<(const QQ &p)const{
        return b<p.b;
    }
}TP[101000];
struct A{
    int a, x, g;
    bool operator <(const A &p)const{
        return a<p.a;
    }
}ord[101000];
void Ins(int a, int b){
    while(a<=n){
        BIT[a] += b;
        a+=(a&-a);
    }
}
long long Sum(int a){
    long long s = 0;
    while(a){
        s += BIT[a];
        a -=(a&-a);
    }
    return s;
}
void Make(int b, int e){
    int i;
    cnt = 0;
    for(i=1;i<=n;i++)tp[i] = w[i], v[i] = 0, P[i] = -1, BIT[i] = 0;
    for(i=b;i<=e;i++){
        if(Q[i].ck == 1){
            int aa = tp[Q[i].a], bb = Q[i].b;
            if(!v[aa]){
                v[aa] = ++cnt;
                B[cnt] = aa;
            }
            if(!v[bb]){
                v[bb] = ++cnt;
                B[cnt] = bb;
            }
            tp[Q[i].a] = Q[i].b;
        }
    }
    OC = 0;
    for(i=1;i<=n;i++){
        if(v[w[i]])continue;
        if(!v[w[i]]){
            ord[OC].a = P[w[i]];
            ord[OC].g = i - P[w[i]];
            ord[OC].x = i;
            OC++;
            P[w[i]] = i;
        }
    }
    sort(ord,ord+OC);
    int TC = 0;
    for(i=b;i<=e;i++){
        if(Q[i].ck==1)continue;
        TP[TC].b = Q[i].a, TP[TC].e = Q[i].b;
        TP[TC].num = i;
        TC++;
    }
    sort(TP,TP+TC);
    int pv = OC-1;
    for(i=TC-1;i>=0;i--){
        while(pv>=0 && ord[pv].a >= TP[i].b){
            Ins(ord[pv].x, ord[pv].g);
            pv--;
        }
        Res[TP[i].num] += Sum(TP[i].e) - Sum(TP[i].b - 1);
    }
}
void Do(int b, int e){
    int i, j;
    for(i=b;i<=e;i++){
        if(Q[i].ck == 1){
            Set[w[Q[i].a]].erase(Q[i].a);
            w[Q[i].a] = Q[i].b;
            Set[Q[i].b].insert(Q[i].a);
            continue;
        }
        else{
            for(j=1;j<=cnt;j++){
                auto it1 = Set[B[j]].lower_bound(Q[i].a), it2 = Set[B[j]].lower_bound(Q[i].b+1);
                if(it2==Set[B[j]].begin() || it1==Set[B[j]].end())continue;
                it2--;
                Res[i] += max((*it2) - (*it1), 0);
            }
        }
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Set[w[i]].insert(i);
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&Q[i].ck,&Q[i].a,&Q[i].b);
    }
    for(i=0;i<m;i+=150){
        Make(i,min(m-1,i+149));
        Do(i,min(m-1,i+149));
    }
    for(i=0;i<m;i++)if(Q[i].ck == 2)printf("%lld\n",Res[i]);
}