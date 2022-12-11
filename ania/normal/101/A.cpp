#include <cstdio>
#include <algorithm>
#include <vector>
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

int n,k;
char s[100100];
int cnt[33];
pi t[33];
int forb[33];

int main()
{
	scanf("%s%d", s, &k);
	for(n = 0; s[n]; n++) ;
	fore(i,n)
	{
		cnt[s[i]-'a']++;
	}
	fore(i,26) t[i] = mp(cnt[i],i);
	sort(t,t+26);
	int p = -1, sum = 0;
	fore(i,26)
	{
		if(sum + t[i].x > k)
		{
			p = i;
			break;
		}
		sum += t[i].x;
	}
	if(p == -1)
	{
		printf("0\n");
		return 0;
	}
	fore(i,p) forb[t[i].y] = 1;
	int res = 0;
	for(int i = p; i < 26; i++) if(t[i].x > 0) res++;
	printf("%d\n", res);
	fore(i,n) if(!forb[s[i]-'a']) printf("%c", s[i]);
	printf("\n");
}