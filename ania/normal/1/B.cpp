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

char s[100], res[100];

void test()
{
	int pos = -1;
	scanf("%s", s);
	if(s[0] == 'R' && '0' <= s[1] && s[1] <= '9')
	{
		for(int i = 2; s[i]; i++) if(s[i] == 'C') pos = i;
	}
	if(pos == -1)
	{
		int i, row = 0, col = 0;
		for(i = 0; 'A' <= s[i] && s[i] <= 'Z'; i++) col = col * 26 + (s[i] - 'A' + 1);
		for(; s[i]; i++) row = row * 10 + (s[i] - '0');
		printf("R%dC%d\n",row,col);
	}
	else
	{
		int row = 0, col = 0, q = 0;
		for(int i = 1; i < pos; i++) row = row * 10 + (s[i] - '0');
		for(int i = pos+1; s[i]; i++) col = col * 10 + (s[i] - '0');
		while(col)
		{
			col--;
			res[q++] = 'A' + col % 26;
			col /= 26;
		}
		for(int i = q-1; i >= 0; i--) printf("%c", res[i]);
		printf("%d\n", row);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) test();
}