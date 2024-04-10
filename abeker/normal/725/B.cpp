#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const char c[] = "fedabc";

int get(char x) {
	return strchr(c, x) - c + 1;
}

int main() {
	char buff[100];
	scanf("%s", buff);
	int len = strlen(buff);
	ll N = 0;
	char seat = buff[len - 1];
	for (int i = 0; i < len - 1; i++)
		N = 10 * N + (ll)(buff[i] - '0');
	N--;
	
	ll mod = N % 4;
	ll who = mod < 2 ? 0 : 2;
	
	ll sol = N / 4 * 12 + N - who + (mod - who) * 6 + get(seat);
	
	printf("%lld\n", sol);
	
	return 0;
}