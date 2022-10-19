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
	int x,y;
	cin >> x >> y;
	if(x<y)x=y;
	switch(x)
	{
	case 1: cout << "1/1\n"; break;
	case 2: cout << "5/6\n"; break;
	case 3: cout << "2/3\n"; break;
	case 4: cout << "1/2\n"; break;
	case 5: cout << "1/3\n"; break;
	case 6: cout << "1/6\n"; break;
	}
}