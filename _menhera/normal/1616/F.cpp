#include <bits/stdc++.h>
using namespace std;

namespace sv{

vector<int> fail = {-2};


const int N = 64, M = 256;
vector<int> solve(vector<tuple<int, int, int>> V)
{
	array<array<int, N>, N> adj;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) adj[i][j] = -1;
	vector<int> res(V.size());
	for(int i=0; i<(int)V.size(); ++i)
	{
		auto [a, b, c] = V[i];
		adj[a][b] = adj[b][a] = i;
		res[i] = c;
	}

	vector<pair<bitset<M>, bitset<M>>> A; vector<int> b;

	auto dbg = [&]()
	{
		return;
		cout << "==" << endl;
		for(int i=0; i<(int)A.size(); ++i)
		{
			for(int j=0; j<(int)V.size(); ++j)
			{
				if(A[i].first[j]) cout << " 1 ";
				else if(A[i].second[j]) cout <<"-1 ";
				else cout << " 0 ";
			}
			cout << " | " << b[i] << endl;
		}
		cout << "==" << endl;
	};

	auto push = [&](int x, int y, int z)
	{
		int xv = get<2>(V[x]), yv = get<2>(V[y]), zv = get<2>(V[z]);

		bitset<M> row, emp; int v = 0;
		if(xv == -1) row.set(x); else v += xv;
		if(yv == -1) row.set(y); else v += yv;
		if(zv == -1) row.set(z); else v += zv;
		v = (3-v%3)%3;
		A.emplace_back(row, emp); b.push_back(v);
		if(xv != -1 && yv != -1 && zv != -1 && v != 0) return false;
		return true;
	};


	for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) for(int k=0; k<j; ++k)
		if(adj[i][j] != -1 && adj[j][k] != -1 && adj[k][i] != -1)
			if(!push(adj[i][j], adj[j][k], adj[k][i])) return fail;

	dbg();

	auto incl = [&](int idx, int iv)
	{
		return A[idx].first[iv] || A[idx].second[iv];
	};

	auto sw = [&](int f, int t)
	{
		if(f != t)
		{
			swap(A[f], A[t]);
			swap(b[f], b[t]);
		}
	};

	auto rev = [&](int idx)
	{
		swap(A[idx].first, A[idx].second);
		if(b[idx]) b[idx] = 3-b[idx];
	};

	auto add = [&](int f, int t, int r)
	{
		if(f == t) return;
		if(!incl(t, r)) return;
		if(A[f].first[r] == A[t].first[r]) rev(t);

		auto fz = ~(A[f].first | A[f].second);
		auto tz = ~(A[t].first | A[t].second);
		auto fi = (A[t].first & fz) | (A[t].second & A[f].second) | (tz & A[f].first);
		auto se = (A[t].second & fz) | (A[t].first & A[f].first) | (tz & A[f].second);
		int res = b[f] + b[t]; if(res >= 3) res -= 3;
		A[t] = {fi, se}; b[t] = res;
	};
	int r = 0;
	{
		int i;
		for(i=0; i<(int)V.size() && r < (int)A.size(); ++i)
		{
			for(int j=r; j<(int)A.size(); ++j)
				if(incl(j, i)){ sw(r, j); break;}
			if(!incl(r, i))
			{
				// they are free variable
				if(res[i] == -1) res[i] = 0;
				continue;
			}

			for(int j=0; j<(int)A.size(); ++j) add(r, j, i);
			++r;
			dbg();
		}
		for(; i< (int)V.size(); ++i) if(res[i] == -1) res[i] = 0;
	}
	

	dbg();
	for(int i=0; i<(int)A.size(); ++i)
	{
		int used=0;
		for(int j=(int)V.size()-1; j>=0; --j)
		{
			if(A[i].first[j])
			{
				if(res[j] != -1)
				{
					b[i] -= res[j];
					if(b[i] < 0) b[i] += 3;
				}
				else res[j] = b[i], b[i] = 0, ++used;
			}
			if(A[i].second[j]) {
				if(res[j] != -1)
				{
					b[i] += res[j];
					if(b[i] >= 3) b[i] -= 3;
				}
				else
				{
					res[j] = 3-b[i];
					if(res[j] == 3) res[j] = 0;
					b[i] = 0;
					++used;
				}
			}
		}
		assert(used <= 1);
		if(b[i] != 0) return fail;
	}

	for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) for(int k=0; k<j; ++k)
		if(adj[i][j] != -1 && adj[j][k] != -1 && adj[k][i] != -1)
			assert((res[adj[i][j]]+ res[adj[j][k]]+res[adj[k][i]])%3 == 0);

	return res;
}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int Q; cin >> Q; while(Q--)
	{
		int N, M; cin >> N >> M; N = 256;
		vector<tuple<int, int, int>> V(M);
		for(auto& [a, b, c]: V)
		{
			cin >> a >> b >> c, --a, --b;
			if(c > 0) --c;
		}
		auto ret = sv::solve(V);
		for(auto x: ret) assert(x != -1), cout << 1+x << " ";
		cout << '\n';
	}
}