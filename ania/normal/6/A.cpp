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

int t[7];

int main()
{
	fore(i,4) scanf("%d",&t[i]);
	sort(t,t+4);
	if(t[0]+t[1] > t[2] || t[1]+t[2] > t[3]) 
	{
		printf("TRIANGLE\n");
		return 0;
	}
	if(t[0]+t[1] == t[2] || t[1]+t[2] == t[3])
	{
		printf("SEGMENT\n");
		return 0;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}