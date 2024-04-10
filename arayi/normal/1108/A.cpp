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
	int q, l1, r1, l2, r2;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 != r2)
			cout << l1 << " " << r2 << endl;
		else if (l2 != r1)
			cout << r1 << " " << l2 << endl;
	}
	return 0;
}