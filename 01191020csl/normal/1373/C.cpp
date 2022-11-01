#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
char s[1000001];
int main() {
	int t = read();
	while (t--) {
		cin >> s + 1;
		int len = strlen(s + 1);
		long long ans = len;
		int minnum = 0, num = 0;
		for (int i = 1; i <= len; i++) {
			if (s[i] == '+') ++num;
			else --num;
			if (num < minnum) minnum = num, ans += i;
		}
		cout << ans << endl;
	}
}