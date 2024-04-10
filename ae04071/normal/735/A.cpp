#include <stdio.h>

int n, k;
char str[200];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	for (int i = 0; i < n; i++){
		if (str[i] == 'G' || str[i] == 'T') {
			bool flag = false;
			for (int j = i + k; j < n; j += k) {
				if (str[j] == 'T' || str[j] == 'G') {
					flag = true;
				}
				else if (str[j] == '#') break;
			}
			if (flag) printf("YES\n");
			else printf("NO\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}