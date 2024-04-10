#include <iostream>
using namespace std;
int cnt[105],arr[105];
int main()
{
	int n;
	cin >> n;
	string ans(n,'A');
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	int a=0,b=0;
	for (int i=0;i<n;i++)
	a+=(cnt[arr[i]]==1);
	for (int i=0;i<n;i++)
	{
		if (cnt[arr[i]]==1 && a>b+1)
		{
			ans[i]='B';
			a--;
			b++;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (cnt[arr[i]]>2 && a==b+1)
		{
			ans[i]='B';
			b++;
			break;
		}
	}
	if (a==b)
	cout << "YES" << endl << ans;
	else
	cout << "NO";
}