#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

int n,m;
char col[7], t[111][111];
int px[4] = {0,1,0,-1}, py[4] = {1,0,-1,0};

int main()
{
	scanf("%d%d%s",&n,&m,col);
	fore(i,n) scanf("%s",t[i]);
	set<char> all;
	fore(i,n) fore(j,m) if(t[i][j] == col[0])
	{
		fore(k,4)
		{
			int x = i+px[k], y = j+py[k];
			if(x<0||y<0||x>=n||y>=m) continue;
			all.insert(t[x][y]);
		}
	}
	all.erase(col[0]);
	all.erase('.');
	printf("%d\n", all.size());
}