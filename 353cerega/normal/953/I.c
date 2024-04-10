#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int ti[111];
int bucket[24 * 60 + 1488];

void out(int i){
	int h = i/60, m = i%60;
	printf("%02d:%02d", h, m);
	exit(0);
}

int main(void) {
	memset(bucket, 0, sizeof(bucket));
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int h, m;
		scanf("%02d:%02d", &h, &m);
		bucket[h * 60 + m] = 1;
	}
	int ptr = 0;
	for(int i = 0; i < 24 * 60 + 1488; i++)if(bucket[i])ti[ptr++] = i;
	if(n == 1){
		out(24 * 60 - 1);
	}
	int ans = 0;
	for(int i = 1; i < n; i++){
		int d = ti[i] - ti[i - 1] - 1;
		ans = ans < d ? d : ans;
	}
	int d = 24 * 60 - 1 - ti[n - 1];
	d = d + ti[0];
	ans = ans < d ? d : ans;
	out(ans);
	return 0;
}