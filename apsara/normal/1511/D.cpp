#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
char s[V];
int n, K;
int main() {
    while (~scanf("%d%d", &n, &K)) {
        int m = 0;
        if (K == 1) {
            s[m++] = 'a';
        } else if (K == 2) {
            s[m++] = 'a';
            s[m++] = 'a';
            s[m++] = 'b';
            s[m++] = 'b';
        }
        else {
            for (int i = 0; i < K; ++i) {
                s[m++] = i + 'a';
                for (int j = i + 1; j < K; ++j) {
                    s[m++] = i + 'a';
                    s[m++] = j + 'a';
                }
            }
        }
        //s[m] = 0;
        //printf("%s\n", s);
        //printf("%d %d %d\n", K, m, K * (K - 1) + K);
        for (int i = m; i < n; ++i) s[i] = s[i - m];
        s[n]= 0;
        printf("%s\n", s);
    }
    return 0;
}

/*
9 4
5 1
10 26
*/