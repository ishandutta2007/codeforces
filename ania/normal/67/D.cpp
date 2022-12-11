#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

#define maxn 1000100

int n,q;
int a[maxn], b[maxn], p[maxn], t[maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for(int i = 0; i < n; i++)
		t[b[i]-1] = i;
	for(int i = 0; i < n; i++)
		p[i] = t[a[i]-1];
	for(int i = 0; i < n; i++)
	{
		int pos = lower_bound(t, t+q, p[i], greater<int>()) - t;
		if(pos == q) q++;
		t[pos] = p[i];
	}
	printf("%d\n", q);
}