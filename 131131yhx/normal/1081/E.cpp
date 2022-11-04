#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#define M 200010
#define int long long
#define P 998244353

using namespace std;

typedef long long ll;

int n, A[M];

struct node {
    int a, b;
    node() {a = 0, b = 0;}
    node(int _1, int _2) {a = _1, b = _2;}
};

vector <int> V[M];

vector <node> S[M];

int Mn[M];

node Ans[M];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n / 2; i++) scanf("%lld", &A[i]);
    ll t = 0;
    for(int i = 1; i * i <= 200000; i++)
        for(int j = i * i; j <= 200000; j += i)
            V[j].push_back(i);
    for(int i = 1; i <= 200000; i++) {
        for(int j = (int) V[i].size() - 1; j >= 0; j--) {
            int a = V[i][j], b = i / a;
            if((a + b) % 2) continue;
            S[i].push_back(node((b - a) / 2, (b + a) / 2));
        }
        //sort(S[i].begin(), S[i].end());
    }
    Mn[0] = 0;
    for(int i = 1; i <= n / 2; i++) {
        Mn[i] = -1;
        for(int j = 0; j < S[A[i]].size(); j++) {
            node tmp = S[A[i]][j];
            if(tmp.a > Mn[i - 1]) {
                Mn[i] = tmp.b;
                Ans[i] = tmp;
                break;
            }
        }
        if(Mn[i] == -1) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for(int i = 1; i <= n / 2; i++) {
        printf("%lld %lld ", Ans[i].a * Ans[i].a - Ans[i - 1].b * Ans[i - 1].b, Ans[i].b * Ans[i].b - Ans[i].a * Ans[i].a);
    }
    return 0;
}