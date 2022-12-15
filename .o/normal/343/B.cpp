#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

const int N_ = 100005;

char D[N_];
int N;
stack<char> S;

int main() {
    int i, j, k;
    
    scanf("%s", D+1);
    N = strlen(D+1);
    
    for(i = 1; i <= N; i++) {
        if(S.empty()) S.push(D[i]);
        else if(S.top() == D[i]) S.pop();
        else S.push(D[i]);
    }
    
    puts(S.empty() ? "Yes" : "No");
    return 0;
}