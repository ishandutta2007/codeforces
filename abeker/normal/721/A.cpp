#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 105;

int N;
char s[MAXN];

int main() {
	scanf("%d%s", &N, s);
	int cnt = 0;
	vector <int> sol;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'B') cnt++;
		if (s[i] == 'W' || i == N - 1){
			if (cnt) 
				sol.push_back(cnt);
			cnt = 0;
		}
	}
		
	printf("%d\n", sol.size());
	for (int i = 0; i < sol.size(); i++)
		printf("%d ", sol[i]);
	puts("");
	return 0;
}