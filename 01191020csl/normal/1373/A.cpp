#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int main() {
	int t = read();
	for (int i = 1; i <= t; i++) {
		int a, b, c;
		a = read(), b = read(), c = read();
		cout << (a<c?1:-1) << ' ' << (c<1ll*a*b?b:-1) << endl;
	}
}