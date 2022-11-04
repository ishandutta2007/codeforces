#include <bits/stdc++.h>

using namespace std;

int l, r, p, ans = 0, S[25], K[25], t = 0, flag;

const int P[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void Search2(int y, int z, int rest, int pre, int lans)
{
	if(p - y - rest < 0) return;
	if(z == 1) {flag = 1, ans++; return;}
	if(p - y - rest == 1) {if(z <= y) flag = 1, ans++; return;}
	int tmp, k = 1;
	for(; k <= t; k++) if(S[K[k]]) {tmp = P[K[k]]; break;}
	for(int i = 1; i <= S[K[k]] && tmp <= p; i++, tmp *= P[K[k]]) {
		if(k != pre || tmp >= lans) S[K[k]] -= i, Search2(max(y, tmp), z / tmp, rest + 1, k, tmp), S[K[k]] += i;
		if(flag) return;
		for(int j = k + 1; j <= t; j++) {
			if(tmp * P[K[j]] > p) break;
			for(int tmp2 = tmp * P[K[j]], s = 1; s <= S[K[j]] && tmp2 <= p; s++, tmp2 *= P[K[j]]) {
				if(k != pre || tmp2 >= lans) S[K[k]] -= i, S[K[j]] -= s, Search2(max(y, tmp2), z / tmp2, rest + 1, k, tmp2), S[K[k]] += i, S[K[j]] += s;
				if(flag) return;
				if(!K[k]) for(int a1 = j + 1; a1 <= t; a1++) {
					for(int tmp3 = tmp2 * P[K[a1]], a2 = 1; a2 <= S[K[a1]] && tmp3 <= p; a2++, tmp3 *= P[K[a1]]) {
						if(k != pre || tmp3 >= lans) S[K[k]] -= i, S[K[j]] -= s, S[K[a1]]--, Search2(max(y, tmp3), z / tmp3, rest + 1, k, tmp3), S[K[k]] += i, S[K[j]] += s, S[K[a1]]++;
						if(flag) return;
					}
				}
			}
		}
	}
}

void Search(int x, int y, int z)
{
	if(z >= l) flag = 0, Search2(P[y], z, 0, 0, 0);
	for(int i = y, lim = min(p - 1, r / z); i < 25 && P[i] <= lim; i++) {
		if(++S[i] == 1) K[++t] = i;
		Search(x + 1, i, z * P[i]);
		if(--S[i] == 0) t--;
	}
}

int main()
{
	scanf("%d%d%d", &l, &r, &p);
	Search(1, 0, 1);
	return printf("%d\n", ans), 0;
}