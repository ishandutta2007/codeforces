#include <bits/stdc++.h>
using namespace std;

char str[100100];
int n;

int main() {
	scanf("%d%s",&n,str);
	for(int i=0;i<n-1;i++) {
		if(str[i]!=str[i+1]) {
			printf("YES\n%c%c",str[i],str[i+1]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}