#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 200;
const int inf = 1e9;
const int T = 50;

int ans[maxn][maxn];

pair < long long, long long > go(int x, long long mn) {
    // x + b * b == a * a;
    long long b = 1, a;
    if (x == 0) return mp(1, 1);
    for (a = 1; a * a - (a - 1) * (a - 1) <= x; a++) {
        for (; x + b * b < a * a; b++);
        if (x + b * b == a * a && b * b > mn)
            return mp(b, a); 
    }
    return mp(-1, -1);
}

bool isSquare(long long t) {
    long long d = sqrt(t);
    return d * d == t;
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {

            for (int a = 1; a < T; a++) {
                for (int c = 1; c < T; c++) {
                    if (!isSquare(a * a * i + c * c * (n - i))) continue;
                    for (int b = 1; b < T ; b++) {
                        if (!isSquare(a * a * j + b * b * (m - j))) continue;
                        for (int d = 1; d < T ; d++) {
                            if (!isSquare(i * b * b + (n - i) * d * d)) continue;
                            if (!isSquare(j * c * c + (m - j) * d * d)) continue;
                            for (int ii = 0; ii < i; ii++)
                                for (int jj = 0; jj < j; jj++)
                                    ans[ii][jj] = a;
                            for (int ii = 0; ii < i; ii++)
                                for (int jj = j; jj < m; jj++)
                                    ans[ii][jj] = b;
                            for (int ii = i; ii < n; ii++)
                                for (int jj = 0; jj < j; jj++)
                                    ans[ii][jj] = c;
                            for (int ii = i; ii < n; ii++)
                                for (int jj = j; jj < m; jj++)
                                    ans[ii][jj] = d;
                            for (int ii = 0; ii < n; ii++, printf("\n"))
                                for (int jj = 0; jj < m; jj++)
                                    printf("%d ", ans[ii][jj]);
                            return 0;
                        }
                    }
                }
            }
        }

    
    printf("fail!!!\n");


    return 0;
}