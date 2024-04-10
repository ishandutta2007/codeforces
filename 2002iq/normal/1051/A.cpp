#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int cnt[]={0,0,0};
		string s;
		cin >> s;
		for (char i:s)
		{
			if (i>='a' && i<='z')
			cnt[0]++;
			else if (i>='A' && i<='Z')
			cnt[1]++;
			else
			cnt[2]++;
		}
		int c=0;
		for (int i=0;i<3;i++)
		c+=(cnt[i]>0);
		if (c==3)
		cout << s << endl;
		else if (c==2)
		{
			int f=0;
			for (char &i:s)
			{
				while (f<3 && cnt[f])
				f++;
				if (f==3)
				break;
				int tmp;
				if (i>='a' && i<='z')
				tmp=0;
				else if (i>='A' && i<='Z')
				tmp=1;
				else
				tmp=2;
				if (cnt[tmp]>1)
				{
					if (!f)
					i='a';
					else if (f==1)
					i='A';
					else
					i='0';
					cnt[tmp]--;
					cnt[f]++;
				}
			}
			cout << s << endl;
		}
		else if (c==1)
		{
			int f=0;
			for (char &i:s)
			{
				while (f<3 && cnt[f])
				f++;
				if (f==3)
				break;
				if (!f)
				i='a';
				else if (f==1)
				i='A';
				else
				i='0';
				cnt[f]++;
			}
			cout << s << endl;
		}
	}
}