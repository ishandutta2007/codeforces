#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 9;

int p[N * 2], q[N * 2];

void op1(int n){
    for (int i = 1; i <= n; ++i){
        swap(q[2 * i - 1], q[2 * i]);
    }
}

void op2(int n){
    for (int i = 1; i <= n; ++i){
        swap(q[i], q[n + i]);
    }
}

bool check(int n){
    for (int i = 1; i <= 2 * n; ++i){
        if (q[i] != i) return false;
    }
    return true;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i){
        scanf("%d", p + i);
    }
    memcpy(q, p, (2 * n + 5) * sizeof(*p));
    int cnt1 = check(n) ? 0 : INT_MAX;
    if (cnt1) for (int i = 1; i <= 2 * n; ++i){
        if (i & 1) op1(n);
        else op2(n);
        if (check(n)){
            cnt1 = i; break;
        }
    }
    memcpy(q, p, (2 * n + 5) * sizeof(*p));
    int cnt2 = check(n) ? 0 : INT_MAX;
    if (cnt2) for (int i = 1; i <= 2 * n; ++i){
        if (i & 1) op2(n);
        else op1(n);
        if (check(n)){
            cnt2 = i; break;
        }
    }
    if (cnt1 == INT_MAX && cnt2 == INT_MAX){
        printf("-1\n");
    }
    else {
        printf("%d\n", min(cnt1, cnt2));
    }
    return 0;
}