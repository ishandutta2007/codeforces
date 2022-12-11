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

char t[11][11];

int main()
{
	int res = 0;
	fore(i,8) scanf("%s", t[i]);
	fore(i,8)
	{
		bool B = 1;
		fore(j,8) if(t[i][j] != 'B') B = 0;
		if(B) res++;
	}
	fore(j,8)
	{
		bool B = 1;
		fore(i,8) if(t[i][j] != 'B') B = 0;;
		if(B) res++;
	}
	if(res == 16) res = 8;
	printf("%d\n", res);
}