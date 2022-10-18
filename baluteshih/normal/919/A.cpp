#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main()
{
	int n;
	double a,b,m,mi=1000000;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a >> b,mi=min(a/b,mi);
	printf("%.6lf\n",m*mi);
}