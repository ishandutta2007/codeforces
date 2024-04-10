#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main() {
    int N;
    scanf("%d", &N);
    ll sol = 1;
    int last = -1;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (!x) continue;
        if (last != -1) 
            sol *= (ll)(i - last);
        last = i;
    }
    if (last == -1) puts("0");
    else cout << sol << endl;
    return 0;
}