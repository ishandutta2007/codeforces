#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 1 << 17;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];

LL res = 0LL;
int Left[N], Right[N];
LL tree[4][T + T + 7];

map <int, int> M;
int prv[N], nxt[N];

void addRes(LL v){
	res = (res + v)%MX;
}

void update(int t2, int p, LL v){
	p += T; v %= MX;
	while(p){
		tree[t2][p] = (tree[t2][p] + v)%MX;
		p >>= 1;
	}
}

LL ask(int t, int from, int to){
	LL ret = 0LL;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret += tree[t][from];
		if(!(to & 1))
			ret += tree[t][to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += tree[t][from];
	return ret%MX;
}

void DC(int from, int to){
	if(to < from)
		return;
	int mid = (from + to) / 2;

	Left[mid] = prv[mid] + 1;
	Right[mid] = nxt[mid] - 1;
	addRes(1LL * (Right[mid] - mid) * (mid - Left[mid]));
	
	priority_queue <PII> Q;
	for(int i = mid + 1; i <= to; ++i){
		Left[i] = max(Left[i - 1], prv[i] + 1);
		Right[i] = min(Right[i - 1], nxt[i] - 1);
		
		if(Left[i] < mid && i < Right[i]){
			Q.push({Left[i], i});
			addRes(1LL * (Right[i] - i) * (mid - Left[i]));
		}
	}
	
	for(int i = mid - 1; i >= from; --i){
		Left[i] = max(Left[i + 1], prv[i] + 1);
		Right[i] = min(Right[i + 1], nxt[i] - 1);
		
		if(Left[i] < i && mid < Right[i]){
			Q.push({Left[i], i});
			update(0, Right[i], 1LL * Right[i] * i);
			update(1, Right[i], Right[i]);
			update(2, Right[i], i);
			update(3, Right[i], 1);
			addRes(1LL * (Right[i] - mid) * (i - Left[i]));
		}
	}	
	
	while(!Q.empty()){
		int t = Q.top().nd;
		Q.pop();
		
		if(t < mid){
			update(0, Right[t], -1LL * Right[t] * t);
			update(1, Right[t], -Right[t]);
			update(2, Right[t], -t);
			update(3, Right[t], -1);
			continue;
		}
		
		LL cur = ask(0, max(mid, t) + 1, Right[t]) + 1LL * t * Left[t] * ask(3, max(mid, t) + 1, Right[t]);
		cur -= 1LL * Left[t] * ask(1, max(mid, t) + 1, Right[t]) + 1LL * t * ask(2, max(mid, t) + 1, Right[t]);
		cur += 1LL * (Right[t] - t) * (ask(2, Right[t] + 1, n) - 1LL * Left[t] * ask(3, Right[t] + 1, n));
		addRes(cur);
	}
//	printf("%d %d :: %d -> %lld\n", from, to, mid, res);	
	for(int i = mid + 1; i <= to; ++i)
		if(Left[i] < mid && i < Right[i]){
			Q.push({Left[i], i});
			update(0, Right[i], Right[i] - i);
		}
	
	for(int i = from; i <= mid - 1; ++i)
		if(Left[i] < i && mid < Right[i])
			Q.push({Left[i], i});
	
	while(!Q.empty()){
		int t = Q.top().nd;
		Q.pop();
		
		if(t > mid){
			update(0, Right[t], t - Right[t]);
			continue;
		}
		
		addRes(1LL * (t - Left[t]) * ask(0, mid + 1, Right[t]));
	}
//	printf("%d %d :: %d -> %lld\n", from, to, mid, res);	
	int last = -1;
	for(int i = mid + 1; i <= to; ++i)
		if(Left[i] < mid && i < Right[i]){
			update(0, Right[i], i);
			update(1, Right[i], 1);
			last = i;
		}
	
	if(last != -1)
		for(int i = mid - 1; i >= from; --i){
			while(last >= Right[i] && last > mid){
				if(Left[last] < mid && last < Right[last]){
					update(0, Right[last], -last);
					update(1, Right[last], -1);
				}
				
				--last;
			}
			
			while(Left[last] >= Left[i] && last > mid){
				if(Left[last] < mid && last < Right[last]){
					update(0, Right[last], -last);
					update(1, Right[last], -1);
				}
				
				--last;
			}
			
			while(Left[last + 1] < Left[i] && last + 1 < Right[i] && last < to){
				++last;
				if(Left[last] < mid && last < Right[last]){
					update(0, Right[last], last);
					update(1, Right[last], 1);
				}
			}
			
			if(Left[i] < i && mid < Right[i])
				addRes(1LL * (i - Left[i]) * (1LL * Right[i] * ask(1, Right[i] + 1, n) - ask(0, Right[i] + 1, n)));
			else
				break;
		}
	
	while(last > mid){
		if(Left[last] < mid && last < Right[last]){
			update(0, Right[last], -last);
			update(1, Right[last], -1);
		}
		
		--last;
	}
	
//	for(int i = 0; i < 4; ++i)
//		for(int j = 1; j < T + T; ++j)
//			assert(tree[i][j] == 0);
	
//	printf("%d %d :: %d -> %lld\n", from, to, mid, res);
	DC(from, mid - 1);
	DC(mid + 1, to);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		M[in[i]] = 0;
	}
	
	for(int i = 1; i <= n; ++i){
		prv[i] = M[in[i]];
		M[in[i]] = i;
	}
	
	for(int i = 1; i <= n; ++i)
		M[in[i]] = n + 1;
	
	for(int i = n; i >= 1; --i){
		nxt[i] = M[in[i]];
		M[in[i]] = i;
	}
	
	DC(1, n);
	printf("%lld\n", (res + MX)%MX);
	return 0;
}