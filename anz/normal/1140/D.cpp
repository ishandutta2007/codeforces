#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	long long result = 0;
	for (int i = 3; i <= n; i++)
		result += i * (i - 1);
	printf("%lld", result);
}