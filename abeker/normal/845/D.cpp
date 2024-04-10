#include <cstdio>
#include <stack>
using namespace std;

int N;
stack <int> S;
int speed;
int cnt;

int main() {
	scanf("%d", &N);
	
	int sol = 0;
	while (N--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &speed);
			for (; !S.empty() && speed > S.top(); S.pop())
				sol++;
		}
		else if (t == 2) {
			sol += cnt;
			cnt = 0;
		}
		else if (t == 3) {
			int limit;
			scanf("%d", &limit);
			if (speed > limit)
				sol++;
			else
				S.push(limit);
		}
		else if (t == 4) 
			cnt = 0;
		else if (t == 5)
			while (!S.empty())
				S.pop();
		else
			cnt++;
	}
	
	printf("%d\n", sol);
	
	return 0;
}