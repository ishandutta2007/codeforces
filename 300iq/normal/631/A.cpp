#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++)
	scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
	scanf("%d", &b[i]);
    int ans = 0;
    for (int l = 0; l < n; l++)  {
	int ta = 0;
	int tb = 0;
	for (int i = l; i < n; i++) {
	    ta |= a[i];
	    tb |= b[i];
	    ans = max(ans, ta + tb);
	}
    }
    printf("%d\n", ans);
}