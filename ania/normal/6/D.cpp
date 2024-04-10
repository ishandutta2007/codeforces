#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

struct solution
{
	vi all;
	int moves;
	solution()
	{
		moves = 0;
		all.resize(20);
	}
	void add(int h, int p)
	{
		all[p] += h;
		moves += h;
	}
	bool operator> (solution x)
	{
		if(moves != x.moves) return moves > x.moves;
		return all > x.all;
	}
};

int n,a,b;
int t[22];
solution dp[22][22][22];
bool vis[22][22][22];

solution f(int x, int y, int pos)
{
	if(x < 0) x = 0;
	if(y < 0) y = 0;
	if(pos == n-2)
	{
		int hits = max((max(x,t[pos+1])+b-1)/b, (y+a-1)/a);
		solution temp;
		temp.add(hits,pos);
		return temp;
	}
	if(vis[x][y][pos]) return dp[x][y][pos];
	vis[x][y][pos] = 1;
	solution ret;
	ret.moves = 1e9;
	for(int hits = (x+b-1) / b; hits < 20; hits++)
	{
		solution temp = f(y-a*hits, t[pos+1]-b*hits, pos+1);
		temp.add(hits,pos);
		if(ret > temp) ret = temp;
	}
	return dp[x][y][pos] = ret;
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	fore(i,n) scanf("%d", &t[i]);
	fore(i,n) t[i]++;
	solution res = f(t[0], t[1], 1);
	printf("%d\n", res.moves);
	fore(i,n) fore(j,res.all[i]) printf("%d ", i+1);
	printf("\n");
}