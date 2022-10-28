#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 20;

char a[N][N];

void update(char &ch)
{
	if(ch != '9')
		ch++;
	else
		ch--;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n = 9;
		for(int i = 1; i <= 9; i++)
			for(int j = 1; j <= 9; j++)
				cin >> a[i][j];
		update(a[1][1]);
		update(a[4][2]);
		update(a[7][3]);
		update(a[2][4]);
		update(a[5][5]);
		update(a[8][6]);
		update(a[3][7]);
		update(a[6][8]);
		update(a[9][9]);
		for(int i = 1; i <= 9; i++)
		{
			for(int j = 1; j <= 9; j++)
				cout << a[i][j];
			cout << endl;
		}

	}
	return 0;
}