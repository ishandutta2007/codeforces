#include<stdio.h>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;
struct Seg{
    int num;
    long long a, b, c;
}w[101000];
int Ans_C;

pii Ans[6];

struct point2{
    pll x, y;
    bool operator<(const point2 &p)const{
        return x != p.x ? x < p.x : y < p.y;
    }
};

bool Inter(Seg p, Seg q){
    if (p.a*q.b == p.b*q.a)return false;
    return true;
}

point2 Gap(Seg p, Seg q){
    point2 ret;
    ret.y.first = (p.a*q.c - p.c*q.a);
    ret.y.second = (p.b*q.a - p.a*q.b);
    ret.x.first = (p.b*q.c - p.c*q.b);
    ret.x.second = (p.a*q.b - p.b*q.a);
    return ret;
}

bool IsOn(Seg p, point2 t){
    if (p.a * t.x.first * t.y.second + p.b * t.y.first * t.x.second + p.c * t.y.second * t.x.second == 0)return true;
    return false;
}

bool Inter3(Seg p, Seg q, Seg r){
    point2 ret = Gap(p, q);
    if (IsOn(r, ret))return true;
    return false;
}

void Push(int a, int b){
    Ans[Ans_C].first = w[a].num;
    Ans[Ans_C].second = (b == -1 ? -1 : w[b].num);
    Ans_C++;
}

int v[101000];

bool DFS(int pv, int n, int K){
    if (pv == n + 1){
        return true;
    }
    int i, j;
    if (v[pv])return DFS(pv + 1, n, K);
    if (!K)return false;
    point2 ret;
    for (i = pv + 1; i <= n; i++){
        if (v[i] || !Inter(w[pv], w[i]))continue;
        ret = Gap(w[pv], w[i]);
        for (j = pv; j <= n; j++){
            if (IsOn(w[j], ret))v[j]++;
        }
        Push(pv, i);
        if (DFS(pv + 1, n, K - 1))return true;
        Ans_C--;
        for (j = pv; j <= n; j++){
            if (IsOn(w[j], ret))v[j]--;
        }
    }
    Push(pv, -1);
    v[pv]++;
    if (DFS(pv + 1, n, K - 1))return true;
    Ans_C--;
    v[pv]--;
    return false;
}

bool Do(int n, int K){
    if (!n)return true;
    if (!K)return false;
    int i, c, a, b, TT = 50;
    if(n <= K*K)return DFS(1, n, K);
    point2 r;
    while (TT--){
        a = rand() % n + 1;
        b = rand() % n + 1;
        if (a == b){
            TT++;
            continue;
        }
        if (!Inter(w[a], w[b]))continue;
        r = Gap(w[a], w[b]);
        c = 0;
        for (i = 1; i <= n; i++)if (IsOn(w[i], r))c++;
        if (c > K)break;
    }
    if (TT < 0) return false;
    Push(a, b);
    c = 0;
    for (i = 1; i <= n; i++){
        if (!IsOn(w[i], r)){
            w[++c] = w[i];
        }
    }
    return Do(c, K - 1);
}
int main(){
    srand(1879);
    int i, n, K;
    scanf("%d%d", &n, &K);
    for (i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &w[i].a, &w[i].b, &w[i].c);
        w[i].num = i;
    }
    if (Do(n, K)){
        printf("YES\n");
        printf("%d\n", Ans_C);
        for (i = 0; i < Ans_C; i++)printf("%d %d\n", Ans[i].first, Ans[i].second);
    }
    else{
        printf("NO\n");
    }
}