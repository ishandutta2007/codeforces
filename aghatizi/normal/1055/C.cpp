#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int la , ra , ta , lb , rb , tb , g;

int get(int k)
{
	int L1 = la / g * g + k;
	if(L1 < la)
		L1 += g;

	int L2 = lb / g * g + k;
	if(L2 < lb)
		L2 += g;
	
	return max(0 , min(ra - L1 + 1 , rb - L2 + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> la >> ra >> ta >> lb >> rb >> tb;

	la %= ta , ra %= ta;
	if(ra < la)
		ra += ta;

	lb %= tb , rb %= tb;
	if(rb < lb)
		rb += tb;
	g = __gcd(ta , tb);

	cout << max(get(la % g) , get(lb % g)) << endl;
}