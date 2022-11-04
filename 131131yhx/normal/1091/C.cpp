#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <bitset>
#define M 2010
#define PI pair <int, int>
#define f first
#define s second
#define int long long

using namespace std;

typedef long long ll;

int n;

vector <ll> V(0);

void Do(int x) {
    ll s = n / x;
    ll v = (1 + (n + 1 - x)) * s / 2;
    V.push_back(v);
}

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i * i <= n; i++) if(n % i == 0) Do(i), Do(n / i);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for(int i = 0; i < V.size(); i++) printf("%lld ", V[i]);
    return 0;
}