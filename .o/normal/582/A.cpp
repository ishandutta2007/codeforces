
#define _CRT_SECURE_NO_WARNINGS

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
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, A[600];
multiset<int>S;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("582A.in", "r", stdin);
    freopen("582A.out", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N*N; i++) {
        int d; scanf("%d", &d);
        S.insert(d);
    }
    for (int i = 0; i < N; i++) {
        A[i] = *S.rbegin(); S.erase(S.find(A[i]));
        for (int j = 0; j < i; j++) {
            int g = gcd(A[i], A[j]);
            S.erase(S.find(g));
            S.erase(S.find(g));
        }
    }
    for (int i = 0; i < N; i++) printf("%d ", A[i]);
    return 0;
}