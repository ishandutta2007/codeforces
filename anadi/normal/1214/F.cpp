#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;

int m, n;
int work[N];
int employee[N];

LL add[N];
int res[N];
map <int, vector <int> > M1, M2;

int sub(int a, int b){
	return (a + m - b) % m;
}

int dist(int a, int b){
	return min(sub(a, b), sub(b, a));
}

void getAll(LL t, int from, int to, int bf){
	int p = lower_bound(work + from, work + to + 1, t - m / 2) - work;
	add[bf + 1] -= t;
	add[p - from + bf + 1] += t + t;

	p = upper_bound(work + p, work + to + 1, t) - work;
	add[p - from + bf + 1] -= t + t;

	p = upper_bound(work + p, work + to + 1, t + m / 2) - work;
	add[p - from + bf + 1] += m + t + t;
	add[to - from + bf + 2] -= m + t;
}

void getAll2(LL t, int from, int to, int bf){
	int p = upper_bound(employee + from, employee + to + 1, t + m / 2) - employee;
	add[bf + 1] += m + t;
	add[to - p + 2 + bf] -= m + t + t;
	
	p = lower_bound(employee + from, employee + to + 1, t) - employee;
	add[to - p + 2 + bf] += t + t;
	
	p = lower_bound(employee + from, employee + to + 1, t - m / 2) - employee;
	add[to - p + 2 + bf] -= t + t;
	add[to - from + 2 + bf] += t;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &work[i]);
		work[i]--;
		M1[work[i]].push_back(i);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", &employee[i]);
		employee[i]--;
		M2[employee[i]].push_back(i);
	}
	
	sort(work + 1, work + n + 1);
	sort(employee + 1, employee + n + 1);
	
	for(int i = n + 1; i <= n + n; ++i){
		work[i] = work[i - n];
		employee[i] = employee[i - n];
	}
	
	LL cur = 0;
	for(int i = 1; i <= n; ++i)
		cur += dist(employee[i], work[i]);
	
	for(int i = 1; i <= n; ++i){
		getAll(employee[i], i, n, 0);
		getAll(employee[i], 1, i - 1, n - i + 1);
	}
	
//	for(int i = 0; i <= n + 1; ++i)
//		printf("%lld ", add[i]);
//	puts("");
	
	for(int i = 1; i <= n; ++i){
		getAll2(work[i], 1, i, 0);
		getAll2(work[i], i + 1, n, i);
	}
	
	int who = 1;
	LL ans = cur; cur = 0;
	for(int i = 1; i <= n; ++i){
		cur += add[i];
		if(cur < ans)
			who = i, ans = cur;
//		printf("%lld ", add[i]);
	}
	
	printf("%lld\n", ans);
	for(int i = 1; i <= n; ++i){
		res[M1[work[i + who - 1]].back()] = M2[employee[i]].back();
		M1[work[i + who - 1]].pop_back();
		M2[employee[i]].pop_back();
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	return 0;
}