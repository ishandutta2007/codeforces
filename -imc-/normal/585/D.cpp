#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

struct solution
{
	int first, second, third;
	ll answer;
	//string s;
	
	void upd(const solution& with)
	{
		if (!answer || with.first > first)
			*this = with;
	}
};

void buildNext(map<pair<int, int>, solution>& sols, int takeA, int takeB, int takeC, int n)
{
	map<pair<int, int>, solution> next;
	for (auto& it: sols)
	{
		const solution& s = it.second;
		for (int take = 0; take < 3; take++)
		{
			solution ta = s;
			if (take == 0)
			{
				ta.first += takeA;
				//ta.s += 'L';
				ta.answer |= 1ULL << (2 * n);
			}
			else if (take == 1)
			{
				ta.second += takeB;
				//ta.s += 'M';
				ta.answer |= 2ULL << (2 * n);
			}
			else if (take == 2)
			{
				ta.third += takeC;
				//ta.s += 'W';
				ta.answer |= 3ULL << (2 * n);
			}
			next[make_pair(ta.second - ta.first, ta.third - ta.first)].upd(ta);
		}
	}
	sols = next;
}

void solve()
{
	int n;
	scanf("%d", &n);
	
	vector<int> takeA(n), takeB(n), takeC(n);
	
	int tsa = 0, tsb = 0, tsc = 0;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &takeA[i], &takeB[i], &takeC[i]);
		tsa += takeA[i];
		tsb += takeB[i];
		tsc += takeC[i];
		
		//takeA[i] = takeB[i] = takeC[i] = 1 << i;
	}
	
	//printf("%d %d %d\n\n", tsa, tsb, tsc);
	
	int middle = n / 2;
	
	int sumA = 0, sumB = 0, sumC = 0;
	for (int i = 0; i <= middle; i++)
	{
		sumA += takeA[i];
		sumB += takeB[i];
		sumC += takeC[i];
	}
	//printf("sums %d %d %d\n", sumA, sumB, sumC);
	
	map<pair<int, int>, solution> direct;
	direct[make_pair(sumB - sumA, sumC - sumA)] = solution { sumA, sumB, sumC, 0 };
	for (int i = 0; i <= middle; i++)
	{
		buildNext(direct, -takeA[i], -takeB[i], -takeC[i], i);
		
		/*if (i > 0) continue;
		printf("after %d:\n", i + 1);
	for (auto& p: direct)
		printf("can %d %d %d (%s)\n", p.second.first, p.second.second, p.second.third, p.second.s.c_str());*/
	}
	
	sumA = sumB = sumC = 0;
	for (int i = n - 1; i > middle; i--)
	{
		sumA += takeA[i];
		sumB += takeB[i];
		sumC += takeC[i];
	}
	
	map<pair<int, int>, solution> rev;
	rev[make_pair(sumB - sumA, sumC - sumA)] = solution { sumA, sumB, sumC, 0 };
	for (int i = n - 1; i > middle; i--)
		buildNext(rev, -takeA[i], -takeB[i], -takeC[i], i);
	
	/*printf("\n");
	for (auto& p: direct)
		printf("can %d %d %d (%s)\n", p.second.first, p.second.second, p.second.third, p.second.s.c_str());
	
	printf("\n");
	for (auto& p: rev)
		printf("can %d %d %d (%s)\n", p.second.first, p.second.second, p.second.third, p.second.s.c_str());
	*/
	int canMax = -1;
	ll answer = 0;
	
	for (auto& p: rev)
	{
		auto pRev = p.first;
		pRev.first *= -1;
		pRev.second *= -1;
		
		auto it = direct.find(pRev);
		if (it != direct.end())
		{
			if (!answer || it->second.first + p.second.first > canMax)
			{
				canMax = it->second.first + p.second.first;
				answer = it->second.answer | p.second.answer;
				//answer = p.second.s;
				//reverse(answer.begin(), answer.end());
				//answer = it->second.s + answer;
			}
		}
	}
	
	
	if (!answer)
		printf("Impossible\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			int c = (answer >> (2 * i)) & 3ULL;
			printf("%s\n", c == 1 ? "MW" : (c == 2 ? "LW" : "LM"));
		}
	}
}

int main()
{
	solve();
	
	return 0;
}