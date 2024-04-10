#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double DD;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PDD pair <DD, DD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = (1 << 21) + 9;

int n, jump;
int K = 1;
int tree[N];

inline void add(int a){
	a += K;
	tree[a] += 1;
	
	while(a > 1){
		a /= 2;
		tree[a] = tree[2 * a] + tree[2 * a + 1];
	}
}

inline int sum(int p, int k){
	p += K;
	k += K;
	int result = 0;
	
	while(p < k){
		if(p & 1)
			result += tree[p];
		if(!(k & 1))
			result += tree[k];
		
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k)
		result += tree[p];
	return result;
}

int main(){
	scanf("%d %d", &n, &jump);
	while(K < n)
		K *= 2;
	--K;
	
	if(2 * jump > n)
		jump = n - jump;
	
	int ile = 0;
	int last = 1;
	long long int result = 1;
	while(ile < n){
		++result;
		int next_step = last + jump;
		if(next_step > n)
			next_step -= n;
		if(next_step < last)
			result += (tree[1] - sum(next_step, last));
		else
			result += sum(last + 1, next_step - 1);

		add(last);
		add(next_step);
		last = next_step;	
		printf("%I64d ", result);
		++ile;
	}

	return 0;
}