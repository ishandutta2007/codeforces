#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N, S, K;
int A[MAXN], dp0[MAXN], dp1[MAXN];
vector<int> next0[MAXN], next1[MAXN];


void p(int x){ if(x<0) printf("%d\n", x); else printf("+%d\n", x);}

void track(int x)
{
	while(true)
	{
		int y = x;
		for(auto v: next0[x]) p(v), y += v;
		y = (y+N)%N;
		if(next1[y].size()) p(next1[y][0]), x = (y+next1[y][0]+N)%N;
		else break;
	}
}

//DP0[i]: cost after reaching here
//DP1[i]: cost after finishing here
int DP1(int);

int DP0(int x)
{
	if(~dp0[x]) return dp0[x];
	int& ans = dp0[x];

	int pmost = -1, mmost = 0;
	for(int i=1; i<N; ++i)
	{
		int y = x+i; if(y >= N) y -= N;
		if(A[x] == A[y])
		{
			pmost = y;
			if(mmost == 0) mmost = y;
		}
	}

	if(pmost == -1) ans = DP1(x);
	else
	{
		int pdir = pmost - x; if(pdir < 0) pdir += N;
		int mdir = x - mmost; if(mdir < 0) mdir += N;
		int pcost = pdir + DP1(pmost), mcost = mdir + DP1(mmost);
		// printf("%d: %d %d %d %d %d %d\n", x, pmost, mmost, pdir, mdir, pcost, mcost);
		if(pcost < mcost)
		{
			ans = pcost;
			int ppos = 0;
			for(int i=1; i<=pdir; ++i)
			{
				++ppos;
				int y = x+i; if(y >= N) y -= N;
				if(A[x] == A[y])
				{
					next0[x].push_back(ppos); ppos = 0;
				}
			}
		}
		else
		{
			ans = mcost;
			int ppos = 0;
			for(int i=1; i<=mdir; ++i)
			{
				--ppos;
				int y = x-i; if(y < 0) y += N;
				if(A[x] == A[y])
				{
					next0[x].push_back(ppos); ppos = 0;
				}
			}
		}
	}
	// printf("(0) %d %d\n", x, ans);
	return ans;
}

int DP1(int x)
{
	if(~dp1[x]) return dp1[x];
	int& ans = dp1[x];

	if(A[x] == K-1)
		return ans = 0;


	int mini = 0, minv = 1e9;
	for(int i=0; i<N; ++i)
	{
		if(A[i] != A[x]+1) continue;
		int d1 = i-x; if(d1 < 0) d1 += N;
		int d2 = d1-N, d;
		if(abs(d1) < abs(d2)) d = d1;
		else d = d2;

		int c = abs(d) + DP0(i);
		if(minv > c)
		{
			minv = c; mini = d;
		}
	}

	next1[x].push_back(mini);
	// printf("(1) %d %d %d\n", x, mini, minv);
	return ans = minv;
}



int main()
{
	scanf("%d%d", &N, &S); --S;
	for(int i=0; i<N; ++i) scanf("%d", A+i);
	vector<int> V(A, A+N);
	sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
	K = V.size();
	for(int i=0; i<N; ++i) A[i] = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
	memset(dp0, -1, sizeof dp0); memset(dp1, -1, sizeof dp1);

	for(int i=0; i<N; ++i) DP0(i), DP1(i);


	int mini = 0, minv = 1e9;
	for(int i=0; i<N; ++i)
	{
		if(A[i] != 0) continue;
		int d1 = i-S; if(d1 < 0) d1 += N;
		int d2 = d1-N, d;
		if(abs(d1) < abs(d2)) d = d1;
		else d = d2;

		int c = abs(d) + DP0(i);
		if(minv > c)
		{
			minv = c; mini = d;
		}
	}
	printf("%d\n", minv);
	p(mini);
	track((S+mini+N)%N);
}