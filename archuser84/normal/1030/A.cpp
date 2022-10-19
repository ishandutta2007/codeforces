#include <iostream>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

int main()
{
	bool ans = 0;
	int n;
	cin >> n;
	for (LoopN)
	{
		bool h;
		cin >> h;
		ans |= h;
	}
	if (ans)
		cout << "hard";
	else
		cout << "easy";
}