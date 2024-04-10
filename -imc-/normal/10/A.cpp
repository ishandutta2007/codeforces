#include <cstdio>
#include <algorithm>

using namespace std;

int n, p1, p2, p3, t1, t2;

int idle (int t)
{
	int answer = 0;
	answer += min (t, t1) * p1;
	t -= min (t, t1);
	answer += min (t, t2) * p2;
	t -= min (t, t2);
	answer += t * p3;
	return answer;
}

int main()
{
	scanf ("%i %i %i %i %i %i", &n, &p1, &p2, &p3, &t1, &t2);

	int answer = 0;

	int lastR = 0;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf ("%i %i", &l, &r);

		if (i > 0)
			answer += idle (l - lastR);

		answer += (r - l) * p1;
		lastR = r;
	}

	printf ("%i\n", answer);

	return 0;
}