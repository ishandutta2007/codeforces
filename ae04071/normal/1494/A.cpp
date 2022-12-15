#include <bits/stdc++.h>
using namespace std;

char str[50];

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		int n, cnt[3] = {0,};
		scanf("%s",str);
		n = strlen(str);

		for(int i=0;i<n;i++) cnt[str[i]-'A']++;
		
		int v = max({cnt[0], cnt[1], cnt[2]}), s = 0;
		if(cnt[0] == v) v = 0;
		else if(cnt[1] == v) v = 1;
		else v = 2;

		if(str[0]-'A' == v) s = 1;
		else s = -1;

		int sum=0;
		for(int i=0;i<n;i++) {
			sum += (str[i] - 'A') == v ? s : -s;
			if(sum < 0) {
				sum = -1;
				break;
			}
		}
		puts(sum == 0 ? "YES" : "NO");
	}
	return 0;
}