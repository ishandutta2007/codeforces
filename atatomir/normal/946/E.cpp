#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, t, i, ti;
char s[maxN];

int cnt[13];

bool check(int rem) {
	int i;
	int need = 0;

	for (i = 0; i < 10; i++)
		need += (cnt[i] & 1);

	return need <= rem;
}

void recons(int best, int sm) {
	int i, need = 0;
	int rem, p;

	memset(cnt, 0, sizeof(cnt));
	s[best] = '0' + sm;


	for (i = 1; i <= best; i++) cnt[s[i] - '0']++;
	for (i = 0; i < 10; i++) 
		need += (cnt[i] & 1);

	rem = n - best - need;
	for (i = 1; i <= rem; i++) s[best + i] = '9';

	p = best + rem;
	for (i = 9; i >= 0; i--) {
		if (cnt[i] & 1) {
			s[++p] = '0' + i;
		}
	}
}

void solve() {
	int i;
	bool ok = false;
	int best = -1;
	int sm;

	if (s[1] != '1') ok = true;
	for (i = 2; i < n; i++)
		if (s[i] != '0')
			ok = true;
	if (s[n] > '1') ok = true;

	if (!ok) {
		for (i = 1; i <= n - 2; i++)
			printf("9");
		printf("\n");
		return;
	}

	memset(cnt, 0, sizeof(cnt));
	for (i = 1; i <= n; i++) {
		if (!(s[i] == '0') && !(s[i] == '1' && i == 1)) {

			for (int act = (i == 1 ? 1 : 0); act < s[i] - '0'; act++) {
				cnt[act]++;
				if (check(n - i)) best = i, sm = act;
				cnt[act]--;
			}
		}

		cnt[s[i] - '0']++;
	}

	recons(best, sm);
	printf("%s\n", s + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &t);
    for (ti = 1; ti <= t; ti++) {
    	scanf("%s\n", s + 1);
    	n = strlen(s + 1);

    	solve();

    	for (i = 1; i <= n; i++) s[i] = '\0';
    }


    return 0;
}