#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200005;
const char dir[] = "LRUD";

int N;
char s[MAXN];
int cnt[2][2];

int main() {
	scanf("%d%s", &N, s);
	
	int sol = 0;
	for (int i = 0; i < N; i++) {
		int pos = strchr(dir, s[i]) - dir;
		cnt[pos / 2][pos % 2]++;
		if (cnt[0][0] * cnt[0][1] || cnt[1][0] * cnt[1][1]) {
			memset(cnt, 0, sizeof cnt);
			cnt[pos / 2][pos % 2]++;
			sol++;
		}
	}
	
	printf("%d\n", sol + 1);
	
	return 0;
}