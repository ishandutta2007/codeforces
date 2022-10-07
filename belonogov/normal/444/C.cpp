#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e5 + 1000;
const int INF = 1e9;
const int BASE = 8;
const int SZ = (1 << BASE) + 1;
//const int MOD = SZ - 1;


int a[N];
long long b[N];
long long bonusB[N];
long long resB[N];
bool useA[N]; //   
long long valA[N];





int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, t, x, l, r; 
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        useA[i / SZ] = 1;
    }

    for (int i = 0; i < m; i++) {
        //cerr << "i: " << i << endl;
        scanf("%d%d%d", &t, &l, &r);
        l--;
        if (t == 2) {
            long long sum = 0;
            for (; l < r; ) {
                int blockId = l / SZ;
                if ((l % SZ) != 0 || l + SZ > r) {
                    sum += b[l] + bonusB[blockId];
                    l++;
                }
                else {
                    sum += resB[blockId] + bonusB[blockId] * SZ;
                    l += SZ;
                }
            }
            printf("%lld\n", sum);
        } 
        if (t == 1) {
            scanf("%d", &x);  
            for (; l < r; ) {
                int blockId = l / SZ;
                if ((l % SZ) != 0 || l + SZ > r) {
                    if (useA[blockId] == 0) {
                        for (int i = 0; i < SZ; i++) {
                            a[(blockId * SZ) + i] = valA[blockId];
                        }
                        useA[blockId] = 1;
                    }
                    resB[blockId] += abs(a[l] - x);
                    b[l] += abs(a[l] - x);
                    a[l] = x; 
                    l++;
                }
                else {
                    if (useA[blockId] == 1) {
                        for (int i = 0; i < SZ; i++, l++) {
                            b[l] += abs(a[l] - x);
                            resB[blockId] += abs(a[l] - x);
                            a[l] = x;
                        }  
                        useA[blockId] = 0;
                        valA[blockId] = x;
                    }
                    else {
                        bonusB[blockId] += abs(valA[blockId] - x);
                        valA[blockId] = x;
                        l += SZ;
                    }
                }
            } 
        }

    }

    return 0;
}