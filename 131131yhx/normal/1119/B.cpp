#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define PII pair <int, int>
#define x first
#define y second
#define int long long

using namespace std;

typedef long long ll;

int n, A[1010], h;

signed main() {
    scanf("%lld%lld", &n, &h);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = 1; i <= n; i++) {
        vector <int> V(0);
        for(int j = 1; j <= i; j++) V.push_back(A[j]);
        sort(V.begin(), V.end());
        ll tot = 0;
        if(V.size() % 2 == 0)
            for(int j = 1; j < V.size(); j += 2) tot += V[j];
        else
            for(int j = 0; j < V.size(); j += 2) tot += V[j];
        if(tot > h) {
            printf("%lld\n", i - 1);
            return 0;
        }
    }
    printf("%lld\n", n);
    return 0;
}