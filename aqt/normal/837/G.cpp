#include <bits/stdc++.h>

using namespace std;

int lft[10000000], rht[100000000], rt[100001];
int lcld[10000000], rcld[10000000];
long long sumleading[10000000], sumtrailing[10000000];
int x1[100005], x2[100005], y1[100005], slope[100005], inter[100005], y2[100005];
int index = 0;
int N;

int cop(int idx){
    index++;
    lft[index] = lft[idx];
    rht[index] = rht[idx];
    sumleading[index] = sumleading[idx];
    sumtrailing[index] = sumtrailing[idx];
    lcld[index] = lcld[idx];
    rcld[index] = rcld[idx];
}

int build(int l, int r){
    index++;
    lft[index] = l;
    rht[index] = r;
    if(l == r){
        return index;
    }
    int mid = (l+r)>>1;
    int i = index;
    lcld[i] = build(l, mid);
    rcld[i] = build(mid+1, r);
    return i;
}

int updleading(int p, int v, int idx){
    idx = cop(idx);
    if(lft[idx] == rht[idx]){
        sumleading[idx] += v;
        return idx;
    }
    int mid = (lft[idx]+rht[idx])>>1;
    if(p <= mid){
        lcld[idx] = updleading(p, v, lcld[idx]);
    }
    else{
        rcld[idx] = updleading(p, v, rcld[idx]);
    }
    sumleading[idx] = sumleading[lcld[idx]] + sumleading[rcld[idx]];
    return idx;
}

int updtrailing(int p, int v, int idx){
    idx = cop(idx);
    if(lft[idx] == rht[idx]){
        sumtrailing[idx] += v;
        return idx;
    }
    int mid = (lft[idx]+ rht[idx])>>1;
    if(p <= mid){
        lcld[idx] = updtrailing(p, v, lcld[idx]);
    }
    else{
        rcld[idx] = updtrailing(p, v, rcld[idx]);
    }
    sumtrailing[idx] = sumtrailing[lcld[idx]] + sumtrailing[rcld[idx]];
    return idx;
}

long long query(int p, int idx){
    if(lft[idx] == rht[idx]){
        return sumleading[idx]*p + sumtrailing[idx];
    }
    int mid = (lft[idx] + rht[idx]) >> 1;
    if(p <= mid){
        return query(p, lcld[idx]);
    }
    else{
        return query(p, rcld[idx]) + sumleading[lcld[idx]] * p + sumtrailing[lcld[idx]];
    }
}

int main(){
    scanf("%d", &N);
    rt[0] = build(0, 200001);
    for(int i = 1; i<=N; i++){
        scanf("%d %d %d %d %d %d", &x1[i], &x2[i], &y1[i], &slope[i], &inter[i], &y2[i]);
        rt[i] = cop(rt[i-1]);
        rt[i] = updtrailing(0, y1[i], rt[i]);
        rt[i] = updtrailing(x1[i]+1, inter[i] - y1[i], rt[i]);
        rt[i] = updtrailing(x2[i]+1, y2[i] - inter[i], rt[i]);
        rt[i] = updleading(x1[i]+1, slope[i], rt[i]);
        rt[i] = updleading(x2[i]+1, -slope[i], rt[i]);
    }
    int Q;
    long long lst = 0;
    scanf("%d", &Q);
    while(Q--){
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        x = (x+lst)%1000000000;
        lst = query(min(x, 200001), rt[r]) - query(min(x, 200001) ,rt[l-1]);
        printf("%lld\n", lst);
    }
}