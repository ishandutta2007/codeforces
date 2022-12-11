#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

long long get(int a, int b, int c, int n)
{
	if(a>n || b>n || c>n) return 0;
	return 1LL * ((n - a + 9) / 9) * ((n - b + 9) / 9) * ((n - c + 9) / 9);
}

int main()
{
	int n;
	long long res=0;
	scanf("%d", &n);
	fore(i,9) fore(j,9)
	{
		int k = i*j%9;
		res += get(i>0?i:9,j>0?j:9,k>0?k:9,n);
	}
	for(int i = 1; i <= n; i++) res -= n/i;
	cout << res << endl;
}