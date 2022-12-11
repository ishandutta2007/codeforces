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

#define maxn 100100

int n;
int64 res;
int p[maxn], c[maxn];

bool lucky(int a)
{
	while(a)
	{
		if(a%10 != 4 && a%10 != 7) return 0;
		a /= 10;
	}
	return 1;
}

int fi(int a)
{
	return a == p[a] ? a : p[a] = fi(p[a]);
}

void un(int a, int b)
{
	int fa = fi(a), fb = fi(b);
	p[fa] = fb;
}

int main()
{
	scanf("%d", &n);
	fore(i,n) p[i] = i;
	fore(i,n-1)
	{
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		if(!lucky(c)) un(a,b);
	}
	fore(i,n) c[fi(i)]++;
	fore(i,n)
	{
		int q = n - c[fi(i)];
		res += 1LL * q * q - q;
	}
	cout << res << endl;
}