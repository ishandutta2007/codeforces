#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> p[maxn];

int a[maxn] , b[maxn];

vector<int> get(int n)
{
	vector<int> ans;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
		{
			ans.pb(i);
			while(n % i == 0)
				n /= i;
		}

	if(n > 1)
		ans.pb(n);

	return ans;
}

void frac(int a , int b)
{
	int g = __gcd(a , b);
	a /= g , b /= g;
	cout << a << " " << b << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> p = get(n);
	sort(p.begin() , p.end());

	if((int)p.size() < 2)
		return cout << "NO" << endl , 0;

	int a = 0 , b = 0 , m = p[0] * p[1];
	for(int i = 0; i * p[1] <= m - 1; i++)
		if((m - 1 - i * p[1]) % p[0] == 0)
		{
			b = i;
			a = (m - 1 - i * p[1]) / p[0];
		}

	a += (n - m) / p[0];
	a *= p[0] , b *= p[1];
	cout << "YES\n2" << endl;
	frac(a , n);
	frac(b , n);
}