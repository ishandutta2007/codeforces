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
const int maxn = -1;
const int inf = 1e9;


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int a, b;
    int j, jj, y, yy;
    scanf("%d%d", &a, &b);
    a = a * a;
    b = b * b;
    for (int i = 1; i * i < a; i++) {
        jj = a - i * i;
        j = sqrt(jj);
        if (j * j == jj) {
            for (int x = 1; x * x < b; x++) {
                yy = b - x * x;
                y = sqrt(yy);
                if (y * y == yy && i != y && j * x == i * y) {
                    printf("YES\n");
                    printf("0 0\n"); 
                    printf("%d %d\n", -j, -i);
                    printf("%d %d\n", x, -y);
                    return 0;
                }
            }
        }
    }
    
    printf("NO\n");



    return 0;
}