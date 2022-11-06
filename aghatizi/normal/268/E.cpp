#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 5e4 + 20;

int l[maxn] , p[maxn] , x[maxn];

bool check(int a , int b)
{
	return l[a] * p[a] * (100 - p[b]) < l[b] * p[b] * (100 - p[a]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> l[i] >> p[i] , x[i] = i;

	sort(x , x + n , check);

	ld sum = 0 , res = 0;

	for(int i = 0; i < n; i++)
	{
		int ind = x[i];
		res += sum * p[ind] / 100.0 * l[ind] + l[ind];
		sum += (100.0 - p[ind]) / 100.0;
	}

	cout << fixed << setprecision(10) << res << endl;
}