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

int n,m,k;
char t[100100], a[111], b[111];
bool f[100100], g[100100];

int main()
{
	scanf("%s%s%s", t,a,b);
	for(n=0;t[n];n++) ;
	for(m=0;a[m];m++) ;
	for(k=0;b[k];k++) ;
	fore(i,n)
	{
		f[i] = 1;
		g[i] = 1;
		fore(j,k) if(b[j] != t[i+j])
		{
			f[i] = 0;
			break;
		}
		fore(j,k) if(i-j < 0 || b[j] != t[i-j])
		{
			g[i] = 0;
			break;
		}
	}
	for(int i = 1; i < n; i++) if(g[i-1]) g[i] = 1;
	for(int i = n-2; i >= 0; i--) if(f[i+1]) f[i] = 1;
	bool forw = 0, back = 0;
	fore(i,n)
	{
		bool F = 1, G = 1;
		if(!forw) fore(j,m) if(a[j] != t[i+j])
		{
			F = 0;
			break;
		}
		if(!back) fore(j,m) if(i-j < 0 || a[j] != t[i-j])
		{
			G = 0;
			break;
		}
		if(F && f[i+m]) forw = 1;
		if(i>=m && G && g[i-m]) back = 1;
	}
	if(forw)
	{
		if(back) printf("both\n");
		else printf("forward\n");
	}
	else
	{
		if(back) printf("backward\n");
		else printf("fantasy\n");
	}
}