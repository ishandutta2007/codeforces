#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int solve(ll x) {
    if (x == 0) return 0;
    vector <ll> bits;
    int cnt = __builtin_popcountll(x);
    for (; x; x /= 2)
        bits.push_back(x % 2);
    reverse(bits.begin(), bits.end());
    int sz = bits.size();
    int sol = (sz - 1) * (sz - 2) / 2;
    for (int i = 1; i < sz && bits[i]; i++) 
        sol++;
    if (cnt == sz - 1) sol++;
    return sol;
}

int main() {
    ll A, B;
    scanf("%I64d%I64d", &A, &B);
    printf("%d\n", solve(B) - solve(A - 1));
    return 0;    
}