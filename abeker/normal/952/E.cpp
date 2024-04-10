#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	int soft = 0, hard = 0;
	while (N--) {
		char type[10];
		scanf("%*s%s", type);
		if (type[0] == 's')
			soft++;
		else
			hard++;
	}
	
	if (soft < hard)
		swap(soft, hard);
	
	for (int i = 1; ; i++) 
		if ((i * i + 1) / 2 >= soft && i * i / 2 >= hard) {
			printf("%d\n", i);
			return 0;
		}
	
	return 0;
}