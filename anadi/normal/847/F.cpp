#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 255;

struct cand{
	int nr, vote, last;
	cand(int _nr = 0, int _vote = 0, int _last = 0){
		nr = _nr;
		vote = _vote;
		last = _last;
	}
};

int n, k, m, a;
cand beg[N];
cand begxd[N];

bool cmp(cand a, cand b){
	if(a.vote == b.vote){
		if(a.last == b.last)
			return a.nr < b.nr;
		return a.last < b.last;
	}
	
	return a.vote > b.vote;
}

void przepisz(int a, int b){
	begxd[a].vote = beg[b].vote;
	begxd[a].last = beg[b].last;
	begxd[a].nr = beg[b].nr;
}
bool canWin(int nr){
	for(int i = 1; i <= n; ++i)
		przepisz(i, i);
	begxd[nr].vote += m - a;
	if(m - a > 0)
		begxd[nr].last = m;
	
	sort(begxd + 1, begxd + n + 1, cmp);
	for(int i = 1; i <= n; ++i)
		if(begxd[i].nr == nr)
			return i <= k && begxd[i].vote > 0;
}

bool canLose(int nr){
	for(int i = 1; i <= n; ++i)
		przepisz(i, i);
	sort(begxd + 1, begxd + n + 1, cmp);
	
	if(beg[nr].vote == 0)
		return true;
	
	bool was = false;
	int ile = 0, used = 0, need = beg[nr].vote + 1;
	for(int i = 1; i <= n; ++i){
		if(ile == k)
			break;
		if(begxd[i].nr == nr){
			was = true;
			continue;
		}
		
		if(!was){
			++ile;
			continue;
		}
		
		used += need - begxd[i].vote;
		++ile;
	}
	
	return used <= m - a && ile >= k;
}

int main(){
	scanf("%d %d %d %d", &n, &k, &m, &a);
	for(int i = 1; i <= n; ++i)
		beg[i].nr = i;

	for(int i = 1; i <= a; ++i){
		int g;
		scanf("%d", &g);
		beg[g].vote += 1;
		beg[g].last = i;
	}
	
	if(n == 1){
		puts("1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		bool val = canWin(i);
		bool val2 = canLose(i);
		if(!val)
			printf("3 ");
		else if(val2)
			printf("2 ");
		else
			printf("1 ");
	}
	
	return 0;
}