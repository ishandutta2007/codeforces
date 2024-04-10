#include <bits/stdc++.h>
using namespace std;
int w[555];
char s[111];
int main()
{
	w['Q']=w['q']=9;
	w['R']=w['r']=5;
	w['B']=w['b']=3;
	w['N']=w['n']=3;
	w['P']=w['p']=1;
	int b=0,h=0;
	for(int i=1;i<=8;i++)
	{
		scanf("%s",s);
		for(int j=0;j<8;j++)
			if(s[j]!='.')
			{
				if(s[j]>='A'&&s[j]<='Z')
					b+=w[s[j]];
				else
					h+=w[s[j]];
			}
	}
	if(b>h)
		puts("White");
	else if(b==h)
		puts("Draw");
	else
		puts("Black");
	return 0;
}