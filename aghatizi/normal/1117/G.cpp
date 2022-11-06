#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 1e6 + 20;

vector<int> query[maxn];

int l[maxn] , r[maxn] , a[maxn] , n;
ll ans[maxn] , fen[2][maxn];

void add(int p , int val , int id)
{
	for(p += 5; p < maxn; p += lb(p))
		fen[id][p] += val;
}

ll get(int p , int id)
{
	ll res = 0;
	for(p += 5; p > 0; p -= lb(p))
		res += fen[id][p];

	return res;
}

int main()
{
	int q;
	scanf("%d%d", &n, &q);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = 0; i < q; i++)
	{
		scanf("%d", &l[i]);
		l[i]--;
	}

	for(int i = 0; i < q; i++)
	{
		scanf("%d", &r[i]);
		r[i]--;
	}

	for(int _ = 0; _ < 2; _++)
	{
		memset(fen , 0 , sizeof fen);

		for(int i = 0; i < q; i++)
			query[l[i]].pb(i);

		stack<int> st;
		for(int i = n - 1; i >= 0; i--)
		{
			while(!st.empty() && a[st.top()] < a[i])
				st.pop();
			int pos = n;
			if(!st.empty())
				pos = st.top();
			st.push(i);

			add(i , -(i - 1) , 0);
			add(pos , i - 1 , 0);
			add(i , 1 , 1);
			add(pos , -1 , 1);

			add(pos , pos - i , 0);

			for(auto ind : query[i])
			{
				ans[ind] += get(r[ind] , 0);
				ans[ind] += 1LL * r[ind] * get(r[ind] , 1);
			}
			query[i].clear();
		}

		for(int i = 0; i < q; i++)
		{
			l[i] = n - l[i] - 1;
			r[i] = n - r[i] - 1;
			swap(l[i] , r[i]);
		}
		reverse(a , a + n);
	}

	for(int i = 0; i < q; i++)
		printf("%lld ", ans[i] - r[i] + l[i] - 1);
	printf("\n");
}