#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXP = 1e2 + 5;
const int INF = 0x3f3f3f3f;

int N, P, M;
char s[MAXN];
int mn[MAXN][MAXP], mx[MAXN][MAXP];
stack <int> S;
vector <int> ch[MAXN];
int mini;

void load() {
	scanf("%s%d%d", s, &P, &M);
}

void calc(int x) {
	assert(ch[x].size() == 2);
	
	int l = ch[x][0], r = ch[x][1];
	for (int i = 0; i <= mini; i++) {
		for (int j = 0; j < i; j++) { 
			mn[x][i] = min(mn[x][i], mn[l][j] + (mini == P ? mn[r][i - j - 1] : -mx[r][i - j - 1]));
			mx[x][i] = max(mx[x][i], mx[l][j] + (mini == P ? mx[r][i - j - 1] : -mn[r][i - j - 1])); 
		}
		for (int j = 0; j <= i; j++) { 
			mn[x][i] = min(mn[x][i], mn[l][j] + (mini == P ? -mx[r][i - j] : mn[r][i - j]));
			mx[x][i] = max(mx[x][i], mx[l][j] + (mini == P ? -mn[r][i - j] : mx[r][i - j]));
		}
	}
}

int solve() {
	memset(mn, INF, sizeof mn);
	memset(mx, -INF, sizeof mx);
	
	mini = min(P, M);
	N = strlen(s);
	
	if (N == 1)
		return s[0] - '0';
		
	for (int i = 0; i < N; i++)
		if (s[i] == '(') 
			S.push(i);
		else if (s[i] == ')') {
			int curr = S.top();
			calc(curr);
			S.pop();
			if (!S.empty())
				ch[S.top()].push_back(curr);
		}
		else if (isdigit(s[i])) {
			ch[S.top()].push_back(i);
			mn[i][0] = mx[i][0] = s[i] - '0';
		}
	
	return mx[0][mini];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}