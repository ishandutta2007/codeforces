
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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = (int)1e6 + 1e3;

int N, K;
char S[N_];
int PI[N_];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main() {

    scanf("%d%d", &N, &K);
    scanf("%s", S + 1);

    PI[1] = 0;
    for (int i = 1; i < N; i++) {
        int j = PI[i];
        while (j > 0 && S[i + 1] != S[j + 1]) j = PI[j];
        if (S[i + 1] == S[j + 1]) ++j;
        PI[i + 1] = j;
    }

    for (int x = 1; x <= N; x++) {
        int pt = x - PI[x];
        int c = x / pt;
        putchar((c % K) < (c / K) || ((x % pt == 0) && (c % K) == c / K) ? '1' : '0');
    }

    return 0;
}