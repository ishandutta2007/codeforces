#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

int N;
char S[1000];
ll fac[100] = {1,1,};
int cnt[100];
string a;

const int primes[] = {2,3,5,7};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    scanf("%d", &N);
    scanf("%s", S);
    for(int i = 0; i < N; i++) {
        int v = S[i] - '0';
        for(int y = 2; y <= v; y++) {
            int x = y;
            for(int j = 0; j <= 3; j++) {
                int p = primes[j];
                while(x % p == 0) ++cnt[j], x /= p;
            }
        }
    }
    
    for(int i = 3; i >= 0; i--) {
        int p = primes[i];
        while(cnt[i] > 0) {
            printf("%d", p);
            for(int y = 2; y <= p; y++) {
                int x = y;
                for(int j = 0; j <= 3; j++) {
                    int p = primes[j];
                    while(x % p == 0) --cnt[j], x /= p;
                }
            }
        }
    }
    
    return 0;
}