#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 513;

int n, m, q;
int sqrtm;
vector <int> x;
vector <int> y;
vector <int> l;
vector <int> r;
vector <int> p;
vector <int> answer;

int f[MAXN], g[MAXN];
int res, ans;
int upd[MAXN], cnt;

bool opr_sort(const int &i, const int &j)
{
	return make_pair(l[i] / sqrtm, -r[i]) < make_pair(l[j] / sqrtm, -r[j]);
}

int mfind(int x, int *next)
{
	if (next == g && upd[x] != cnt)
	{
		upd[x] = cnt;
		g[x] = f[x];
	}
	
	if (next[x] != x) next[x] = mfind(next[x], next);
	return next[x];
}


void munion(int x, int y, int *next, int &result)
{
	x = mfind(x, next);
	y = mfind(y, next);
	if (x == y)
		return;
	result -= 1;
	if (rand() & 1)
		next[x] = y;
	else
		next[y] = x;
}


int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &m);
	sqrtm = sqrt(m + 1);
	x.resize(m);
	y.resize(m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	scanf("%d", &q);
	
	l.resize(q);
	r.resize(q);
	p.resize(q);
	answer.resize(q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
		l[i] -= 1;
		r[i] -= 1;
		p[i] = i;
	}
	sort(p.begin(), p.end(), opr_sort);
	
	for (int I = 0, J = 0; I < (int)p.size(); I = J)
	{
		for (int i = 1; i <= n; i++)
			f[i] = i;
		res = n;
		cnt += 1;

		for (int i = 0; i < l[p[I]] / sqrtm * sqrtm; i++)
			munion(x[i], y[i], f, res);
			
		int last = m - 1;
		while (J < (int)p.size() && l[p[I]] / sqrtm == l[p[J]] / sqrtm)
		{
			while (last > r[p[J]])
			{
				munion(x[last], y[last], f, res);
				last--;
			}
			
			cnt++;
			ans = res;
			for (int i = l[p[J]] / sqrtm * sqrtm; i < l[p[J]]; i++)
			{
				munion(x[i], y[i], g, ans);
			}
//			cout << p[J] << endl;
			answer[p[J]] = ans;
			J++;
		}
	}
	for (int i = 0; i < (int)answer.size(); i++)
		printf("%d\n", answer[i]);
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}