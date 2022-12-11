#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

#define MOD 1000003

void wrong()
{
	printf("0\n");
	exit(0);
}

string s[500500];

int main()
{
	int n,m;
	int res=1;
	cin >> n >> m;
	fore(i,n) cin >> s[i];
	fore(i,n)
	{
		int tp = -1;
		fore(j,m) if(s[i][j] != '.')
		{
			int tp2 = (j&1) == (s[i][j]<'3');
			if(tp != -1 && tp != tp2) wrong();
			tp = tp2;
		}
		if(tp == -1) res = res * 2 % MOD;
	}
	fore(j,m)
	{
		int tp = -1;
		fore(i,n) if(s[i][j] != '.')
		{
			int tp2 = (i&1) == (s[i][j]=='1'||s[i][j]=='4');
			if(tp != -1 && tp != tp2) wrong();
			tp = tp2;
		}
		if(tp == -1) res = res * 2 % MOD;
	}
	printf("%d\n", res);
}