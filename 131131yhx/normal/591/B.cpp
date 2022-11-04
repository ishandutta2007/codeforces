#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char ch[27], K[200010];

int main()
{
	for(int i = 0; i < 26; i++) ch[i] = i + 'a';
	int n, m;
	scanf("%d%d\n", &n, &m);
	scanf("%s", K + 1);
	char a[3], b[3];
	for(int i = 1; i <= m; i++)
	{
		scanf("%s%s", a, b);
		int s = 'a';
		for(int j = 0; j < 26; j++)
			if(ch[j] == a[0])
				ch[j] = b[0];
			else if(ch[j] == b[0])
				ch[j] = a[0];
		
	}
	for(int i = 1; i <= n; i++)
		K[i] = ch[K[i] - 'a'];
	printf("%s", K + 1);
	return 0;
}