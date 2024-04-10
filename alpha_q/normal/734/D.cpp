#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int INF = 2e9 + 5;

struct data {
	int id, x, y;
	data () {id = x = y = 2e9 + 10;}
	data (int a, int b, int c) {
		id = a, x = b, y = c;
	}
};

char s[3];
data d[10];
int n, x00, y00;

int main (int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &x00, &y00);
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%s %d %d", s, &x, &y);
		x -= x00, y -= y00;
		int id;
		if (s[0] == 'B') id = 0;
		else if (s[0] == 'R') id = 1;
		else id = 2;

		if (x == 0 and y > 0 and y < d[0].y) {
			d[0].y = y, d[0].id = id; 
		} 

		else if (x == 0 and y < 0 and -y < d[1].y) {
			d[1].y = -y, d[1].id = id;
		}

		else if (y == 0 and x > 0 and x < d[2].x) {
			d[2].x = x, d[2].id = id;
		}

		else if (y == 0 and x < 0 and -x < d[3].x) {
			d[3].x = -x, d[3].id = id;
		} 

		else if (x == y and x > 0 and x < d[4].x) {
			d[4].x = x, d[4].id = id;
		}

		else if (x == y and x < 0 and -x < d[5].x) {
			d[5].x = -x, d[5].id = id;
		}

		else if (x == -y and x < 0 and -x < d[6].x) {
			d[6].x = -x, d[6].id = id;
		}

		else if (x == -y and x > 0 and x < d[7].x) {
			d[7].x = x, d[7].id = id;
		}
	}

	if (d[0].id == 1 or d[0].id == 2) {
		puts("YES");
		return 0;
	}

	if (d[1].id == 1 or d[1].id == 2) {
		puts("YES");
		return 0;
	}

	if (d[2].id == 1 or d[2].id == 2) {
		puts("YES");
		return 0;
	}
	
	if (d[3].id == 1 or d[3].id == 2) {
		puts("YES");
		return 0;
	}

	if (d[4].id == 0 or d[4].id == 2) {
		puts("YES");
		return 0;
	}
	
	if (d[5].id == 0 or d[5].id == 2) {
		puts("YES");
		return 0;
	}
	
	if (d[6].id == 0 or d[6].id == 2) {
		puts("YES");
		return 0;
	}
	
	if (d[7].id == 0 or d[7].id == 2) {
		puts("YES");
		return 0;
	}

	puts("NO");
	return 0;
}