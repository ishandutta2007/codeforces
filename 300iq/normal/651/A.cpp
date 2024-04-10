#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    while (max(a, b) - 2 >= 0) {
        if (a > b)
            swap(a, b);
        while (b - 2 >= 0) {
            a++;
            b -= 2;
            ans++;
        }
    }
    printf("%d\n", ans - (ans > 0));
}