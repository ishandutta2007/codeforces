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

bool v[333];
char s[12345];

char lower(char x)
{
	if(x >= 'A' && x <= 'Z') return x - 'A' + 'a';
	return x;
}

void proc(char x)
{
	if(v[x]) return;
	printf(".%c", x);
}

int main()
{
	v['a'] = v['o'] = v['y'] = v['e'] = v['u'] = v['i'] = 1;
	scanf("%s", s);
	for(int i = 0; s[i]; i++)
		proc(lower(s[i]));
	printf("\n");
	return 0;
}