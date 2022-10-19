#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n;
	int p[50];
	cin >> n;
	n /= 2;
	for(LoopN)
	{
		cin >> p[i];
	}
	sort(p, p + n);
	int W=0 , B=0;
	for(int i=2*n; i>0; i-=2)
	{
		W += abs(i-p[i/2 - 1]);
		B += abs(i-1-p[i/2 - 1]);
	}
	cout << (W<B? W: B) << '\n';
}