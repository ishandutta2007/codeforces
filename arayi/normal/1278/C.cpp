#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); 
using namespace std;
//https://codeforces.com/problemset/problem/1278/C
const int N = 4e5 + 30;
long long int n, m, k, l, pat, s, arayi, p;
long long int a[N], tex[N];
long long int sm;
int main() {
 
	fastio;
	cin >> s;
	while (s--)
	{
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> a[i];
			tex[i] = -1;
		}
		tex[2 * n] = -1;
		tex[n] = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1) sm++;
			else sm--;
			tex[sm + n] = i + 1;
		}
		pat = 2 * n - tex[n];
		for (int i = 2 * n - 1; i >= n; i--)
		{
			arayi++;
			if (a[i] == 1) l++;
			else l--;
			if (tex[-l + n] != -1)
			{
				if (n - arayi + n - tex[-l + n] < pat)
					pat = n - arayi + n - tex[-l + n];
			}
		}
		cout << pat << endl;
		arayi = sm = l = 0;
	}
	return 0;
}
/*
   __
 *(><)*
   \/ /
   ||/
 --||
   ||
   /\
  /  \
 /    \
 
*/