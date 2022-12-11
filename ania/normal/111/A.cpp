#include <cstdio>
#include <algorithm>
#include <vector>
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

int main()
{
	int64 n,x,y;
	cin >> n >> x >> y;
	if(n > y)
	{
		printf("-1\n");
		return 0;
	}
	int64 a = y-n+1;
	int64 s = n-1 + a*a;
	if(s < x)
	{
		printf("-1\n");
		return 0;
	}
	fore(i,n-1) cout << "1\n";
	cout << a << "\n";
	return 0;
}