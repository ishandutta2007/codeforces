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

const int maxn = 2e5;
const int inf = 1e9;

struct node{
    int b;
    double x;
    long long dp;
    node(){}
    node(int b, double x, long long dp): b(b), x(x), dp(dp) {};
};

int n;
int a[maxn];
int b[maxn];
node stack[maxn];
int cur = 0;

void reading(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]); 
}

long long fastsolve(){
    stack[cur++] = node(b[0], 0, 0);
    int j = 0;
    for (int i = 1; i < n; i++){
        epr("cur %d\n", cur);
        for (; j + 1 < cur && stack[j + 1].x < a[i]; j++);
        long long sum = stack[j].dp + a[i]*1ll* stack[j].b;
        for (;stack[cur - 1].x > (stack[cur - 1].dp - sum) * 1.0 / (b[i] - stack[cur - 1].b); cur--); 
        stack[cur] = node(b[i], (stack[cur - 1].dp - sum) * 1.0 / (b[i] - stack[cur - 1].b), sum);
        cur++;
    }
    return stack[cur - 1].dp;
}



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    
    reading();
    cout << fastsolve() << "\n";
 
    return 0;
}