#include <cstdio>
using namespace std;
    
typedef long long ll;

int A, B;

void load() {
    scanf("%d%d", &A, &B);
}

ll sqr(int x) {
    return (ll)x * x;
}

void output(int cnt, char c) {
    while (cnt--) putchar(c);
}

void solve() {
    if (!A) {
        printf("%I64d\n", -sqr(B));
        output(B, 'x');
        puts("");
        return;
    }
    if (!B) {
        printf("%I64d\n", sqr(A));
        output(A, 'o');
        puts("");
        return;
    }
    
    ll sol = (ll)-1e15;
    int x = 0, y = 0;
    for (int i = 1; i <= A; i++) {
        ll sum = (ll)(i - 1) + sqr(A - i + 1);
        for (int j = -1; j < 2; j++) {
            int k = i + j;
            if (k < 1 || k > B) continue;
            ll val = sum - (ll)(k - B % k) * sqr(B / k) - (ll)(B % k) * sqr(B / k + 1);
            if (val > sol) {
                sol = val;
                x = i;
                y = k;
            } 
        }
    }
    
    printf("%I64d\n", sol);
    if (x < y) {
        for (int i = 0; i < x; i++) {
            output(B / y + (i < B % y), 'x');
            output(i ? 1 : A - x + 1, 'o');
        }
        output(B / y, 'x');
    }
    else {
        for (int i = 0; i < y; i++) {
            output(i ? 1 : A - x + 1, 'o');
            output(B / y + (i < B % y), 'x');
        }
        if (x > y) output(1, 'o');
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}