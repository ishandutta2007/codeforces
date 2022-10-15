#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int d = 3; d <= n; d++) {
        if (n % d) continue;
        int gap = n / d;
        for (int i = 1; i <= gap; i++) {
            int works = 1;
            for (int j = i; j <= n; j += gap) {
				//printf("%d ", j);
                if (!a[j]) works = 0;
            }
			//printf("\n");
            if (works) return 0 * printf("YES\n");
        }
    }
    printf("NO\n");
}