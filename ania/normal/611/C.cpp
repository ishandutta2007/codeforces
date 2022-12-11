#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 555;
int n,m;
int row[maxn][maxn], col[maxn][maxn], sumrow[maxn][maxn], sumcol[maxn][maxn];
char s[maxn][maxn];

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%s", s[i]);
	FORI(i,n-1) {
		row[i][0]=s[i][0]=='.'&&s[i-1][0]=='.';
		sumrow[i][0] = sumrow[i-1][0] + row[i][0];
		REP(j,1,m-1) {
			row[i][j] = row[i][j-1] + (s[i][j]=='.'&&s[i-1][j]=='.');
			sumrow[i][j] = sumrow[i-1][j] + row[i][j];
			//printf("row[%d][%d] = %d %d\n", i, j, row[i][j], sumrow[i][j]);
		}
	}
	FORI(j,m-1) {
		col[0][j]=s[0][j]=='.'&&s[0][j-1]=='.';
		sumcol[0][j] = sumcol[0][j-1] + col[0][j];
		REP(i,1,n-1) {
			col[i][j] = col[i-1][j] + (s[i][j]=='.'&&s[i][j-1]=='.');
			sumcol[i][j] = sumcol[i][j-1] + col[i][j];
			//printf("col[%d][%d] = %d %d\n", i, j, col[i][j], sumcol[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	FOR(_,q) {
		int r1,c1,r2,c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--; c1--; r2--; c2--;
		int rows = sumrow[r2][c2] - (r1==0?0:sumrow[r1-1][c2]) - (c1==0?0:sumrow[r2][c1-1])
					+ (r1==0?0:c1==0?0:sumrow[r1-1][c1-1]);

		int cols = sumcol[r2][c2] - (r1==0?0:sumcol[r1-1][c2]) - (c1==0?0:sumcol[r2][c1-1])
					+ (r1==0?0:c1==0?0:sumcol[r1-1][c1-1]);


		//printf("%d %d\n", rows, cols);

		rows -= row[r1][c2] - (c1==0?0:row[r1][c1-1]);
		cols -= col[r2][c1] - (r1==0?0:col[r1-1][c1]);

		printf("%d\n", rows+cols);
	}
	return 0;
}