#include <stdio.h> 
#include <time.h>
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 505, M_ = 505;

int N, M, K;
char D[N_][M_];

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

queue<int> que;
vector<int> vec;
bool Chk[N_][M_];

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &M, &K);
	for(i = 0; i < N; i++) scanf("%s", D[i]);

	for(i = 0; i < N; i++) for(j = 0; j < M; j++) {
		if(D[i][j] == '.') {
			que.push(i); que.push(j);
			Chk[i][j] = true;
			goto bfs;
		}
	}

bfs:
	while(!que.empty()) {
		int x = que.front(); que.pop();
		int y = que.front(); que.pop();
		vec.push_back(x);
		vec.push_back(y);

		for(k = 0; k < 4; k++) {
			i = x+dx[k], j = y+dy[k];
			if(0 <= i && i < N && 0 <= j && j < M && D[i][j] == '.' && !Chk[i][j]) {
				Chk[i][j] = true;
				que.push(i); que.push(j);
			}
		}
	}

	for(i = 0, j = (int)vec.size() - 1; i < K; i++) {
		int y = vec[j--];
		int x = vec[j--];
		D[x][y] = 'X';
	}

	for(i = 0; i < N; i++) puts(D[i]);
	return 0;
}