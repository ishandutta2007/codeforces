#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr. __VA_ARGS__)

#define fore(i,n) for(int i = 0; i < n; i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef pair<int,int> pi;
typedef vector<int> vi;

#define maxn 111

int n,m;
char s[maxn][maxn], t[maxn], q[maxn];
char letter;
int v[maxn];

int main()
{
	scanf("%d", &n);
	fore(i,n) scanf("%s", s[i]);
	scanf("%s %c", t, &letter);
	for(m=0;t[m];m++) ;
	fore(i,m) if('A' <= t[i] && t[i] <= 'Z') q[i] = t[i] - 'A' + 'a';
	else q[i] = t[i];
	fore(i,n) for(int j = 0; s[i][j]; j++) if('A' <= s[i][j] && s[i][j] <= 'Z') s[i][j] -= 'A' - 'a';
	fore(i,n)
	{
		fore(j,m)
		{
			int k;
			for(k = 0; s[i][k] && q[j+k]; k++)
				if(s[i][k] != q[j+k]) break;
			if(!s[i][k]) for(k = 0; s[i][k]; k++) v[j+k] = 1;
		}
	}
	char fst = 'a';
	if(letter == 'a') fst = 'b';
	fore(i,m) if(v[i])
	{
		if(q[i] != letter)
			t[i] = t[i] - q[i] + letter;
		else
			t[i] = t[i] - q[i] + fst;
	}
	printf("%s\n", t);
}