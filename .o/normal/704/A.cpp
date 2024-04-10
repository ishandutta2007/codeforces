#include <stdio.h>
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
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, Q;

const int Q_ = 300500;
const int N_ = 300500;

bool used[Q_];
queue<int> que;
vector<int> apps[N_];
int ans, num;

void read (int a) {
	if(!used[a]) used[a] = true, ans -= 1;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int q = 1; q <= Q; q++) {
		int type; scanf("%d", &type);
		if(type == 1) {
			int x; scanf("%d", &x);
			num += 1; ans += 1;
			que.push(num);
			apps[x].push_back(num);
		}else if(type == 2) {
			int x; scanf("%d", &x);
			for(auto a : apps[x]) read(a);
			apps[x].clear();
		}else {
			int t; scanf("%d", &t);
			while(!que.empty() && que.front() <= t) {
				read(que.front());
				que.pop();
			}
		}

		printf("%d\n", ans);
	}
    return 0;
}