#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct node
{
	node *ch[22];
	node *link;
	node *parent;
	int pchar;
	int idx;
	int val;
	int sum;
	
	node()
	{
		for (int i = 0; i < 22; i++)
			ch[i] = NULL;
		link = NULL;
		parent = NULL;
		val = 0;
		sum = -1;
		idx = 0;
	}
};

node *tree[500];
int ncnt = 1;

void addStr(vector < int > &str, int val)
{
	node *v = tree[0];
	for (int i = 0; i < str.size(); i++)
	{
		if (v->ch[str[i]] == NULL)
		{
			v->ch[str[i]] = new node();
			v->ch[str[i]]->idx = ncnt++;
			v->ch[str[i]]->parent = v;
			v->ch[str[i]]->pchar = str[i];
			tree[v->ch[str[i]]->idx] = v->ch[str[i]];
		}
		v = v->ch[str[i]];
	}
	
	v->val += val;
}

node* go(node *v, int s);

node* getLink(node *v)
{
	if (v->link == NULL)
	{
		if (v->parent == NULL)
			v->link = v;
		else if (v->parent->parent == NULL)
			v->link = v->parent;
		else
		{
			node *lnk = getLink(v->parent);
			v->link = go(lnk, v->pchar);
		}
	}
	
	return v->link;
}

node* go(node *v, int s)
{
	if (v->ch[s] == NULL)
	{
		if (v->parent == NULL)
			v->ch[s] = v;
		else
		{
			node *lnk = getLink(v);
			v->ch[s] = go(lnk, s);
		}
	}		
	
	return v->ch[s];
}

int getSum(node *v)
{
	if (v->sum == -1)
	{
		v->sum = v->val;
		node *lnk = getLink(v);
		
		if (lnk != v)
			v->sum += getSum(lnk);
	}
	
	return v->sum;
}

const int mod = 1000000007;

int dp[205][205][505][2][2];
int k, m;
int a[205];

ll rec(int pos, int tpos, int sum, int less, int zero)
{
	//cerr << pos << " " << tpos << " " << sum << " " << less << " " << zero << endl;
	if (sum > k)
		return 0;
	
	if (pos == -1)
	{
		if (sum <= k && zero)
			return 1;
		else
			return 0;
	}
	
	if (dp[pos][tpos][sum][less][zero] != -1)
		return dp[pos][tpos][sum][less][zero];
		
	ll res = 0;
	
	int ub = a[pos];
	
	if (less)
		ub = m - 1;
		
		
	for (int i = 0; i <= ub; i++)
	{
		node *to = tree[tpos];
		if (zero || i)
			to = go(to, i);
		res += rec(pos - 1, to->idx, sum + getSum(to), less || i < ub, zero || i);
	}
	
	res %= mod;
	
	return dp[pos][tpos][sum][less][zero] = res;
}

ll solve(vector < int > &v)
{
	for (int i = 0; i < v.size(); i++)
		a[v.size() - 1 - i] = v[i];
		
	for (int i = 0; i < 205; i++)
		for (int j = 0; j < 205; j++)
			for (int h = 0; h < 505; h++)
				for (int i1 = 0; i1 < 2; i1++)
					for (int i2 = 0; i2 < 2; i2++)
						dp[i][j][h][i1][i2] = -1;
						
	return rec(v.size() - 1, 0, 0, 0, 0);
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n;
	scanf("%d %d %d", &n, &m, &k);
	
	vector < int > l, r;
	
	int len;
	scanf("%d", &len);
	
	for (int i = 0; i < len; i++)
	{
		int x;
		scanf("%d", &x);
		l.pb(x);
	}
	
	reverse(l.begin(), l.end());
	l[0]--;
	
	for (int i = 0; i < l.size(); i++)
	{
		if (l[i] < 0)
		{
			l[i] += m;
			l[i + 1]--;
		}
		else
			break;
	}
	
	while (l.size() > 1 && l.back() == 0) l.pop_back();
	
	reverse(l.begin(), l.end());
	
	
	scanf("%d", &len);
	
	for (int i = 0; i < len; i++)
	{
		int x;
		scanf("%d", &x);
		r.pb(x);
	}
	
	tree[0] = new node();
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &len);
		
		vector < int > v;
		
		for (int j = 0; j < len; j++)
		{
			int x;
			scanf("%d", &x);
			v.pb(x);
		}
		
		int val;
		scanf("%d", &val);
		
		addStr(v, val);
	}
	
	//for (int i = 0; i < ncnt; i++)
	//	cerr << getSum(tree[i]) << endl;
	
	cout << (solve(r) - solve(l) + mod) % mod << endl;
	
	return 0;
}