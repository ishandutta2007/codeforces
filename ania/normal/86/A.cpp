#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)
//#define err(...)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define x first
#define y second
#define tr(i,c) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

long long gen(int x)
{
	long long r = 1;
	while(x > 0)
	{
		x /= 10;
		r *= 10;
	}
	return r;
}

int main()
{
	int a,b;
	scanf("%d%d", &a, &b);
	long long c = gen(b);
	if(a <= c/2 && c/2 <= b)
	{
		cout << 1LL * (c/2) * (c/2-1) << endl;
		return 0;
	}
	if(c/2 > b)
	{
		cout << 1LL * b * (c-1-b) << endl;
		return 0;
	}
	cout << 1LL * a * (c-1-a) << endl;
}