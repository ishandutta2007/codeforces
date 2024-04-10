#include <cstdio>
using namespace std;

int N;
int sum[15];
bool has[15];

int main() {
	scanf("%d", &N);
	while (N--) {
		char cmd;
		int x;
		scanf(" %c%d", &cmd, &x);
		for (int i = 0; i < 10; i++) {
			int bit = x >> i & 1;
			if (cmd == '^') {
				if (bit) 
					sum[i] ^= 1;
			}
			else if (cmd == '|') {
				if (bit) {
					sum[i] = 1;
					has[i] = true;
				}
			}
			else {
				if (!bit) {
					sum[i] = 0;
					has[i] = true;
				}
			}
		}
	}
	
	int a = 0, b = 1023, c = 0;
	for (int i = 0; i < 10; i++)
		if (has[i]) {
			if (sum[i])
				a ^= 1 << i;
			else
				b ^= 1 << i;
		}
		else if (sum[i])
			c ^= 1 << i;
		
	puts("3");
	printf("| %d\n", a);
	printf("& %d\n", b);
	printf("^ %d\n", c);
			
	return 0;
}