#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
char s[101];
int main() {
	int t = read();
	while (t--) {
		cin >> s + 1;
		int c1 = 0, c2 = 0, len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			if (s[i] == '0') ++c1;
			else ++c2;
		if (min(c1, c2) & 1) puts("DA");
		else puts("NET");
	}
}