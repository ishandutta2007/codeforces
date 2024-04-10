#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)


const int maxn = 2e5;

long long sum[maxn * 4];
long long upd[maxn * 4];

void push(int v, int len){
    sum[v * 2] += upd[v] * len;
    sum[v * 2 + 1] += upd[v] * len;
    upd[v * 2] += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v] = 0;
}

void add(int v, int l, int r, int ll, int rr, long long val){
    if (l > rr || ll > r) return ;
    if (l <= ll && rr <= r){
        sum[v] += val * (rr - ll + 1);
        upd[v] += val;
        return ;
    }
    push(v, (rr - ll + 1) / 2);
    add(v * 2, l, r, ll, (ll + rr) / 2, val);
    add(v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr, val);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
}


long long getsum(int v, int l, int r, int ll, int rr){
    if (l > rr || ll > r) return 0;
    if (l <= ll && rr <= r){
        return sum[v];
    }
    push(v, (rr - ll + 1) / 2);
    return getsum(v * 2, l, r, ll, (ll + rr) / 2) +
           getsum(v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr);
}



int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, cnt, x, r, t, st;
    scanf("%d", &n);
    for(st = 1; st < n + 10; st *= 2);
    cnt = 1;
    cout.precision(15);
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d%d", &r, &x);
            add(1, 0, r - 1, 0, st - 1, x);
        }
        if (t == 2){
            scanf("%d", &x);
            add(1, cnt, cnt, 0, st - 1, x);
            cnt++;
        }
        if (t == 3){
            cnt--;
            add(1, cnt, cnt, 0, st - 1, -getsum(1, cnt, cnt, 0, st - 1));

        }
      //  cerr << "cnt " << cnt << endl;
        cout << fixed << getsum(1, 0, cnt - 1, 0, st - 1) * 1.0 / cnt << "\n";
       // for(int i = 0; i < st * 2; i++)
        //    printf("%d ", sum[i]);
        //printf("\n");
    }



    return 0;

}