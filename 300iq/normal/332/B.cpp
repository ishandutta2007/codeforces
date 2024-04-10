#include <bits/stdc++.h>

using namespace std;

long long pref[200010];
pair <long long, int> maxs[200010];
int x[200000];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
	scanf("%d", &x[i]);
    pref[0] = x[0];
    for (int i = 1; i < n; i++) 
	pref[i] = pref[i - 1] + x[i];
    long long ans = 0;
    int l, r;
    for (int a = n - k; a >= 0; a--) {
	long long s = pref[a + k - 1] - pref[a - 1];
	maxs[a] = maxs[a + 1];
	if (maxs[a].first <= s) {
	    maxs[a].first = s;
	    maxs[a].second = a;
	}
	if (s + maxs[a + k].first >= ans) {
	    ans = s + maxs[a + k].first;
	    l = a;
	    r = maxs[a + k].second;
	}
    }
    l++, r++;
    printf("%d %d\n", l, r);
}