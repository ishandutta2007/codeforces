#include<algorithm>
#include<iostream>
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

#define maxn 5050

int n;
long long res;
int t[maxn], df[maxn];

int main()
{
	scanf("%d", &n);
	fore(i,n) scanf("%d", &t[i]);
	int cur = t[0];
	fore(i,n) if(t[i] > cur) cur = t[i];
	fore(i,n)
	{
		df[i] = cur - t[i];
		res += df[i];
	}
	//fore(j,n) printf("%d ", df[j]); printf("\n");
	for(int i = n-1; i >= 0; i--)
	{
		int cnt = 1, mx = 1e9, best = 1;
		while(cnt > 0 && cnt == best)
		{
			cnt = 0;
			mx = 1e9;
			best = 0;
			for(int j = 0; j <= i; j++)
			{
				if(df[j] > 0) cnt++;
				else cnt--;
				if(cnt > best) best = cnt;
				if(df[j] > 0 && df[j] < mx) mx = df[j];
			}
			if(cnt > 0 && cnt == best)
			{
				//printf("usuwam %d na poz %d\n", mx, i);
				res -= 1LL * mx * cnt;
				for(int j = 0; j <= i; j++) df[j] -= mx;
			}
		}
		//fore(j,n) printf("%d ", df[j]); printf("\n");
	}
	cout << res << endl;
}