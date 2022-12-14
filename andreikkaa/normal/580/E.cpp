/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input = "", const string output = "")
{
	if(not input.empty())
		assert(freopen(input.c_str(), "r", stdin) != nullptr);

	if(not output.empty())
		assert(freopen(output.c_str(), "w", stdout) != nullptr);
}

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _pre()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

const int MAX_N = 4 * (100 * 1000 + 1);
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAG = 11;

int a[MAX_N];
ll h[MAX_N];
bool ch[MAX_N];
int chv[MAX_N];

ll MAG_POW[MAX_N];
ll PRE[MAX_N][10];

ll res(ll h1, ll h2, int l2)
{
	return (h1 * MAG_POW[l2] + h2) % MOD;
}

ll build_tree(int v, int l, int r)
{
	if(r - l == 1)
	{
		h[v] = PRE[1][a[l]];
	}
	else
	{
		h[v] = res(build_tree(2 * v, l, (l + r) / 2),
		           build_tree(2 * v + 1, (l + r) / 2, r), r - (l + r) / 2);
	}

	return h[v];
}

void push_tree(int v, int l, int r)
{
	if(not ch[v])
	{
		return;
	}

	ch[v] = false;
	h[v] = PRE[r - l][chv[v]];

	if(r - l > 1)
	{
		ch[2 * v] = ch[2 * v + 1] = true;
		chv[2 * v] = chv[2 * v + 1] = chv[v];
	}
}

ll update_tree(int v, int l, int r, const int L, const int R, const int C)
{
	push_tree(v, l, r);

	if(R <= l or r <= L)
	{
		return h[v];
	}

	if(L <= l and r <= R)
	{
		ch[v] = true;
		chv[v] = C;

		return PRE[r - l][C];
	}

	h[v] = res(update_tree(2 * v, l, (l + r) / 2, L, R, C),
	           update_tree(2 * v + 1, (l + r) / 2, r, L, R, C), r - (l + r) / 2);

	return h[v];
}

pair<ll, int> get_tree(int v, int l, int r, int L, int R)
{
	push_tree(v, l, r);

	if(R <= l or r <= L)
	{
		return {0, 0};
	}

	if(L <= l and r <= R)
	{
		return {h[v], r - l};
	}

	auto r1 = get_tree(2 * v, l, (l + r) / 2, L, R);
	auto r2 = get_tree(2 * v + 1, (l + r) / 2, r, L, R);

	return {res(r1.first, r2.first, r2.second), r1.second + r2.second};
}

void _solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	string s;
	cin >> s;

	for(int i = 0; i < n; ++i)
	{
		a[i] = s[i] - '0';
	}

	for(int j = 0; j < 10; ++j)
	{
		for(int i = 1; i < MAX_N; ++i)
		{
			PRE[i][j] = (PRE[i - 1][j] * MAG + (j + 1)) % MOD;
		}
	}

	MAG_POW[0] = 1;
	for(int i = 1; i < MAX_N; ++i)
	{
		MAG_POW[i] = (MAG_POW[i - 1] * MAG) % MOD;
	}

	build_tree(1, 0, n);

	for(int i = 0; i < m + k; ++i)
	{
		int p, l, r, c;
		cin >> p >> l >> r >> c;

		if(p == 1)
		{
			update_tree(1, 0, n, l - 1, r, c);
		}
		else
		{
			if(get_tree(1, 0, n, l - 1, r - c) == get_tree(1, 0, n, l - 1 + c, r))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}