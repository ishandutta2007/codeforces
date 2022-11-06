#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
struct stdt
{
	int a, b;

	bool operator<(const stdt &s) const
	{
		return a - b > s.a - s.b;
	}
};
stdt student[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &student[i].a, &student[i].b);
	sort(student, student + n);
	ll result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (ll)student[i].a*i + (ll)student[i].b*(n - i - 1);
	}
	printf("%lld", result);
}