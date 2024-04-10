#include <iostream>
using namespace std;
int cnt[26];
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (char i:s)
	cnt[i-'a']++;
	for (int i=0;i<26;i++)
	{
		if (cnt[i]>1 || n==1)
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}