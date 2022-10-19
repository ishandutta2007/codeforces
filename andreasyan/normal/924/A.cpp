#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 52;
char a[N][N];
int n, m;
bool r[N], c[N];
bool vr[N], vc[N];

bool check()
{
	int i,j,i2,k;
	int first;
	for (j = 0; j < m; j++) {
		first = -1;
		for (i = 0; i < n; i++)
			if (a[i][j] == '#') {
				if (first == -1)
					first = i;
				else
					if (strcmp(a[i], a[first]) != 0)
						return false;
			}
	}
	return true;
}

int main()
{
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	if (check())
		cout << "Yes\n";
	else
		cout << "No\n";
//	system("pause");
	return 0;
}