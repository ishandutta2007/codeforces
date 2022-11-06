#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

bool visited[maxn][maxn];

int n , ax , ay;

bool is_good(int x , int y)
{
	if(x < 1 || x > n || y < 1 || y > n || x == ax || y == ay || x + y == ax + ay  || x - y == ax - ay)
		return 0;
	else
		return 1;
}

void dfs(int x , int y)
{
	visited[x][y] = 1;

	for(int dx = -1; dx <= 1; dx++)
		for(int dy = -1; dy <= 1; dy++)
			if(is_good(x + dx , y + dy) && !visited[x + dx][y + dy])
				dfs(x + dx , y + dy);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> ax >> ay;

	int bx , by;
	cin >> bx >> by;

	dfs(bx , by);

	int cx , cy;
	cin >> cx >> cy;

	if(visited[cx][cy])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}