#include <bits/stdc++.h>
#define M 2000010

using namespace std;

int n, A[M], Lis[M], Sz = 0, ans = 0;

int Ans1[M], Ans2[M], tmp[M];

bool Pend(int x, int S)
{
	if(x % 2 == S)
		return (A[x] < A[x - 1] || x == 1) && (A[x] < A[x + 1] || x == n);
	else
		return (A[x] > A[x - 1] || x == 1) && (A[x] > A[x + 1] || x == n);
}

bool Solve(int x, int y, int S)
{
	if(x < 1 || x > n || y < 1 || y > n) return 0;
	if(x == y) return 0;
	swap(A[x], A[y]);
	for(int i = max(x - 5, 1); i <= min(x + 5, n); i++) if(!Pend(i, S)) return swap(A[x], A[y]), 0;
	for(int i = max(y - 5, 1); i <= min(y + 5, n); i++) if(!Pend(i, S)) return swap(A[x], A[y]), 0;
	return swap(A[x], A[y]), 1;
}

bool cmp(int x, int y)
{
	return Ans1[x] < Ans1[y] || Ans1[x] == Ans1[y] && Ans2[x] < Ans2[y];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	// /\/\/\/
	Sz = 0;
	for(int i = 2; i <= n; i++)
		if(i % 2 == 1 && A[i] >= A[i - 1] || i % 2 == 0 && A[i] <= A[i - 1]) Lis[++Sz] = i;
	if(Sz <= n)
	{
		if(Sz >= 2 && !(Sz == 2 && abs(Lis[2] - Lis[1]) <= 2))
		{
			int a = Lis[1], b = Lis[Sz];
			for(int i = max(a - 5, 1); i <= min(a + 5, n); i++)
				for(int j = max(b - 5, 1); j <= min(b + 5, n); j++)
				{
					swap(A[i], A[j]);
					int getans = 1;
					for(int k = 2; k <= n; k++)
						if(k % 2 == 1 && A[k] >= A[k - 1] || k % 2 == 0 && A[k] <= A[k - 1])
						{
							getans = 0;
							break;
						}
					swap(A[i], A[j]);
					if(getans) Ans1[++ans] = i, Ans2[ans] = j, tmp[ans] = ans;
				}
		}
		else
		{
			int a = Lis[1];
			for(int i = 1; i <= n; i++)
			{
				if(Solve(a, i, 1)) Ans1[++ans] = a, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a - 1, i, 1)) Ans1[++ans] = a - 1, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a - 2, i, 1)) Ans1[++ans] = a - 2, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a - 3, i, 1)) Ans1[++ans] = a - 3, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a - 4, i, 1)) Ans1[++ans] = a - 4, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a + 1, i, 1)) Ans1[++ans] = a + 1, Ans2[ans] = i, tmp[ans] = ans;
				if(Solve(a + 2, i, 1)) Ans1[++ans] = a + 2, Ans2[ans] = i, tmp[ans] = ans;
			}
		}
	}
	for(int i = 1; i <= ans; i++) if(Ans1[i] > Ans2[i]) swap(Ans1[i], Ans2[i]);
	sort(tmp + 1, tmp + ans + 1, cmp);
	if(ans == 0) printf("%d\n", 0);
	else
	{
	int aans = 1;
	for(int i = 1; i < ans; i++)
		if(Ans1[tmp[i]] != Ans1[tmp[i + 1]] || Ans2[tmp[i]] != Ans2[tmp[i + 1]]) aans++;
	printf("%d\n", aans);}
	return 0;
}