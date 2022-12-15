#include <stdio.h>
#include <algorithm>
#include <utility>

typedef std::pair<int, int> iPair;

int n, m;
iPair p[200000], s[200000];
bool cp[200000], cs[200000];

int con[200000], use[200000];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i].first);
		s[i].second = i;
	}
	std::sort(p, p + n);
	std::sort(s, s + m);
	
	int tCom = 0, tUse = 0, u = 0;
	for (int k = 0; k < 32; k++) {
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (cp[i]) i++;
			else if (cs[j]) j++;
			else if (p[i].first == s[j].first) {
				cp[i] = true; cs[j] = true;
				con[p[i].second] = s[j].second + 1;
				use[s[j].second] = u;
				tUse += u; tCom++;
				i++; j++;
			}
			else if (p[i].first > s[j].first) {
				j++;
			}
			else
				i++;
		}
		for (int i = 0; i < m; i++)
		{
			if (s[i].first % 2) s[i].first = s[i].first / 2 + 1;
			else s[i].first = s[i].first / 2;
		}
		u++;
	}

	printf("%d %d\n", tCom, tUse);
	for (int i = 0; i < m; i++) printf("%d ", use[i]);
	printf("\n");
	for (int i = 0; i < n; i++) printf("%d ", con[i]);
	printf("\n");

	return 0;
}