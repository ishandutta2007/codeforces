#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	if (a+1 == b) printf("%d %d", a, b);
	else if (a == b) printf("%d %d", a*10, a*10+1);
	else if (a == 9 && b == 1) printf("9 10");
	else printf("-1");
	return 0;
}