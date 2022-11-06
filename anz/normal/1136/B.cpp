#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	printf("%d", 3 * n + min(k - 1, n - k));
}