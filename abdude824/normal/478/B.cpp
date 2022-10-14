#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define chlo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()

#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jj.txt", "w", stdout);
#endif
}
bool solveknightmove(int[][8], int, int, int, int);
void printboard(int[][8], int);
bool canplace(int [][8], int n, int, int);

int32_t main()
{
	aeh();
	int n, m;
	cin >> n >> m;
	if (m != 1) {
		int mx =  (n - m + 1) * (n - m) / 2;
		int p = n / m;
		int c =  (p) * (p - 1) / 2;
		int d = m - (n % m);
		c = c * d;
		p++;

		int r = (n % m) * ((p) * (p - 1) / 2);
		int mnn = r + c;
		cout << mnn << " " << mx << endl;
	}
	else {
		if (m == 1)
		{
			int j = n * (n - 1) / 2;
			cout << j << " " << j << endl;
		}
	}
}
bool solveknightmove(int board[8][8], int n, int move_no, int currow, int curcol)
{
	int rowdir[] = { +2, +1, -1, -2, -2, -1, +1, +2};
	int coldir[] = { +1, +2, +2, +1, -1, -2, -2, -1};

	for (int curdir = 0; curdir < 8; ++curdir)
	{	int nextrow = currow + rowdir[curdir];
		int nextcol = curcol + coldir[curdir];

		if (canplace(board, n, nextrow, nextcol) == true)
			board[nextrow][nextcol] = move_no + 1;

		if (solveknightmove(board, n, move_no + 1, nextrow, nextcol))
			return true;

		board[nextrow][nextcol] = 0;
	}
	return false;
}

bool canplace(int board[8][8], int n, int r, int c)
{	return (r >= 0 && r < n && c >= 0 && c < n && board[r][c] == 0);
}

void printboard(int board[8][8], int n)
{
	for (int i = 0; i < n; i++)
	{	for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
	}
	cout << endl;
}