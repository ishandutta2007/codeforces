#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, k, c;
LL A[N];
bool flag, Flag[N];

inline LL Abs(LL x)
{
	return x > 0 ? x : -x;
}

struct Node
{
	int id;
	LL fix;
	Node (int _id = 0, LL _fix = 0) {id = _id, fix = _fix;}
	bool operator < (const Node a) const
	{
		return Abs(fix) > Abs(a.fix);
	}
};

priority_queue <Node> Q;

int main()
{
	scanf("%d%d%d", &n, &k, &c);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%I64d", A + i);
		if (A[i] < 0) flag ^= 1, Flag[i] ^= 1;
		A[i] = Abs(A[i]);
		Q.push(Node(i, A[i]));
	}
	while (k --)
	{
		Node x = Q.top();
		Q.pop();
		if (!flag)
		{
			A[x.id] -= c;
			if (A[x.id] < 0) flag = 1;
		}
		else A[x.id] = (A[x.id] < 0 ? -1 : 1) * (Abs(A[x.id]) + c);
		Q.push(Node(x.id, A[x.id]));
	}
	for (int i = 1; i <= n; i ++)
		printf("%I64d%c", A[i] * (Flag[i] ? -1 : 1), i == n ? '\n' : ' ');
	return 0;
}