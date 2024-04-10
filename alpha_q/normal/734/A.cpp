#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;

#define x first
#define y second
#define mp make_pair

const int N = 1e5 + 10;

int n;
char s[N];

int main (int argc, char const *argv[]) {
	scanf("%d %s", &n, s + 1);

	int a = 0, d = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'A') ++a;
		else ++d;
	}

	if (a == d) puts("Friendship");
	else if (a > d) puts("Anton");
	else puts("Danik");
	return 0;
}