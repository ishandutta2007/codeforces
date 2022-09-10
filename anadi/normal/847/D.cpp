#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
int n, T, t[N];
int pref[N];

int main()
{
	scanf("%d%d", &n, &T);
	T--;
	for (int i = 1; i <= n; ++ i) 
	{
		scanf("%d", &t[i]);
		t[i] = max(0, t[i] - i);
		if(i <= T - t[i]){
			pref[i]++;
			pref[min(T - t[i], n) + 1]--;
		}
	}

	int cur = 0, res = 0;
	for(int i = 1; i <= n; ++i)
		cur += pref[i],
		res = max(res, cur);
	printf("%d\n", res);	
	return 0;
}