#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;

int main(){
	char in[10];
	scanf("%s", in);
	int r = in[6] - '0';
	cout << (r & 1) << "\n";
	return 0;
}