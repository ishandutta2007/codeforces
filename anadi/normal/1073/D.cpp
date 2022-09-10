#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int T = 1 << 18;

int n;
LL res, m;
int cnt[T + T + 7];
LL tree[T + T + 7];

void update(int x){
	x += T;
	tree[x] = cnt[x] = 0;
	while(x > 1){
		x >>= 1;
		cnt[x] = cnt[x + x] + cnt[x + x + 1];
		tree[x] = tree[x + x] + tree[x + x + 1];
	}
}

LL get(int from, int to){
	LL ret = 0;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret += tree[from];
		if(!(to & 1))
			ret += tree[to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += tree[to];
	return ret;
}

int get2(int from, int to){
	int ret = 0;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret += cnt[from];
		if(!(to & 1))
			ret += cnt[to];
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += cnt[to];
	return ret;
}

int find(LL sub){
	int ret = 1; LL cur = m;
	while(ret < T){
		ret += ret;
		if(tree[ret] <= cur + sub){
			cur -= tree[ret];
			++ret;
		}
	}
	
	return ret - T;
}

int main(){
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &tree[i + T]);
		cnt[i + T] = 1;
	}
	
	for(int i = T - 1; i >= 1; --i){
		cnt[i] = cnt[i + i] + cnt[i + i + 1];
		tree[i] = tree[i + i] + tree[i + i + 1];
	}
	
	int place = 1;
	while(cnt[1]){
		res += m / tree[1] * cnt[1];
		m %= tree[1];

		LL c = get(1, place - 1);
		int ile = get2(1, place - 1);

		if(tree[1] - c <= m){
			res += cnt[1] - ile;
			m -= tree[1] - c;
			place = 1;
			continue;
		}
		
		int id = find(c);
		res += get2(place, id - 1);
		m -= get(place, id - 1);
		
		place = id;
		update(id);
	}
	
	printf("%lld\n", res);
	return 0;
}