#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k;
map<int, int> was;
deque < int > q;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(was[x])
			continue;
		if(q.size() == k){
			was[q.back()] = 0;
			q.pop_back();
		}
		was[x] = 1;
		q.push_front(x);
	}
	printf("%d\n", q.size());
	while(!q.empty()){
		printf("%d ", q.front());
		q.pop_front();
	}
	return 0;
}