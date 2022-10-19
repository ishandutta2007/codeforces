#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main()
{
	int n,m;
	cin>>m>>n;
	double hope = 0.0;
	double probaMayorI = 0.0;
	for (int i = m; i >= 1; i--)
	{
		double menorIgualI = pow((double) i/m+.0,n);
		double menorIgualImenos1 = pow((double) (i-1)/m+.0,n);
		double exactamenteI = menorIgualI - menorIgualImenos1;
		hope += exactamenteI * (double) i;
	}
	cout<<hope<<'\n';
}