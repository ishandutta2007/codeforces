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




int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	int x, y, z;
	cin >> x >> y >> z >> a >> b >> c;
	if (a >= x && a + b >= x + y && a + b + c >= x + y + z)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}