// Neal submission - https://codeforces.com/contest/1101/submission/48312743
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> basis;
    int everything = 0;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        everything ^= a;

        for (int x : basis)
            a = min(a, a ^ x);

        if (a != 0) {
            basis.push_back(a);
 //           sort(basis.rbegin(), basis.rend());
        }
    }

    printf("%d\n", everything == 0 ? -1 : (int) basis.size());
}