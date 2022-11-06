#include <stdio.h>
#include <algorithm>
#include <queue>

struct str
{
	int l;
	char a[7];
};

char arr[36][3];
char tmp[7];
char res[7];
bool chk[200000];
std::queue<str> que;

int main()
{
	int r = 0, b, h, n, q, l, i, j;
	str t;
	scanf("%d%d", &n, &q);
	for(i = 0; i<q; i++)
		scanf("%s %c", arr[i], &arr[i][2]);

	t.l = 1;
	t.a[0] = 'a';
	chk[1] = 1;
	que.push(t);
	while(!que.empty())
	{
		l = que.front().l;
		for(i = 0; i<l; i++)
			tmp[i] = que.front().a[i];
		que.pop();
		for(i = 0; i<q; i++)
		{
			if(tmp[0]==arr[i][2])
			{
				str nex;
				nex.l = l+1;
				nex.a[0] = arr[i][0];
				nex.a[1] = arr[i][1];
				for(j = 1; j<l; j++)
					nex.a[j+1] = tmp[j];

				b = 1;
				h = 0;
				for(j = 0; j<l+1; j++)
				{
					h += b*(nex.a[j]-'a'+1);
					b *= 7;
				}
				if(!chk[h])
				{
					chk[h] = 1;
					if(l+1==n)
						r++;
					else
						que.push(nex);
				}
			}
		}
	}
	printf("%d", r);
	return 0;
}