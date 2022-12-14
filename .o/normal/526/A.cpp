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

char s[500];
int n;

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    for (int p = 0; p < n; p++) {
        for (int d = 1; p + d < n; d++) {
            int c = -1, i = -1;
            for (c = 0, i = p; c < 5 && i < n; c++, i += d) {
                if (s[i] != '*') break;
            }
            if (c == 5) return 0 & puts("yes");
        }
    }
    puts("no");
    return 0;
}