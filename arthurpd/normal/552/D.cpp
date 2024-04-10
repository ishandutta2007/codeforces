#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int x[2123], y[2123];
typedef pair<int,int> pii;

int abs(int x) { return x < 0 ? -x : x; }
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	long long ans = (n*(n-1ll)*(n-2ll))/6ll;
	for(int i = 0; i < n; i++)
	{
		map<pii, int> rdm;
		for(int j = i+1; j < n; j++) 
			rdm[pii((x[j] - x[i]) / gcd((x[j] - x[i]), (y[j] - y[i])), (y[j] - y[i]) / gcd((x[j] - x[i]), (y[j] - y[i])))]++;
		for(map<pii, int>::iterator it = rdm.begin(); it != rdm.end(); it++)
			ans -= (it->second * (it->second - 1ll)) / 2ll; 
	}
	cout << ans << '\n';
}