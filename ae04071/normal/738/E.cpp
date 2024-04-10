#include <stdio.h>
#include <algorithm>

int n, m;
int arr[200000];
int main()
{
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	if (arr[m - 1] != 0) {
		arr[m - 1] = 0;
		cnt++;
	}
	std::sort(arr, arr + n);
	int st = 1, en = n;
	int nonzero = 0;
	while (st < n && arr[st] == 0){
		nonzero++;
		st++;
	}
	for (; st < en; st++) {
		if (arr[st] - arr[st - 1] > 1) {
			int dist = arr[st] - arr[st - 1] - 1;
			if (dist <= nonzero) {
				cnt += dist;
				nonzero -= dist;
			}
			else {
				cnt += nonzero;
				dist -= nonzero;
				nonzero = 0;

				if (en - st <= dist) {
					cnt += (en - st);
					break;
				}
				en -= dist;
				cnt += dist;
			}
		}
	}
	cnt += nonzero;
	printf("%d\n", cnt);

	return 0;
}