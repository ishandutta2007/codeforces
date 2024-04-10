#include<cstdio>
#include<algorithm>
using namespace std;
int n, ck, s;
char p[10100];
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		if (p[i] == '1')ck = 1;
		if (ck && p[i]=='0')s++;
	}
	if (s >= 6)puts("yes");
	else puts("no");
}