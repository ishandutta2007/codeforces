#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 2e5 + 1;
const lli oo = 1e18;
lli n1, k, pat = oo;
int i1;
pair <lli, int> sm[N];
lli qan(lli a1)
{
	lli sum = 0;
	for (lli pw = a1; pw <= n1 && pw%a1 == 0; pw *= a1)
	{
		sum += n1 / pw;
		//cout<<pw<<endl;
	}

	return sum;
}
void mpf(lli n)
{
	lli sm = 0;
	if (n % 2 == 0)
	{
		
		while (n % 2 == 0) {
			sm++;
			n >>= 1;
		}
		pat = min(pat, qan(2) / sm);
		sm = 0;
	}
	
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0)
		{
			
			while (n % i == 0) {
				sm++;
				n /= i;
			}
			pat = min(pat, qan(i) / sm);
			sm = 0;
		}
	}
	if (n != 1)
	{
		pat = min(pat, qan(n));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n1 >> k;
	mpf(k);
	cout << pat;
	return 0;
}