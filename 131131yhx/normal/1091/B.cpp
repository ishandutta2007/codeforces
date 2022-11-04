#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <bitset>
#define M 2010
#define PI pair <int, int>
#define f first
#define s second

using namespace std;

int X[M], Y[M], A[M], B[M], n;

set <PI> hsh;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);
    for(int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]), hsh.insert(PI(X[i], Y[i]));
    for(int i = 1; i <= n; i++) {
        int a = X[i] + A[1], b = Y[i] + B[1], flag = 1;
        for(int j = 2; j <= n; j++) {
            int x = a - A[j], y = b - B[j];
            if(!hsh.count(PI(x, y))) flag = 0;
        }
        if(flag) {printf("%d %d\n", a, b); return 0;}
    }
    return 0;
}