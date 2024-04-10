#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    int x1, x2, x3;
    scanf("%d%d%d", &x1, &x2, &x3);
    if (x1 > x2) swap(x1, x2);
    if (x1 > x3) swap(x1, x3);
    if (x2 > x3) swap(x2, x3);
    printf("%d\n", x2 - x1 + x3 - x2);
}