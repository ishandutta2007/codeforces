#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

char str[100005];
int lett[10];

int main()
{
	gets(str);
	int len = strlen(str);
	
	int qcnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]))
			lett[str[i]-'A'] = 1;
		qcnt += (str[i] == '?');
	}
			
	int lettcnt = 0;
	
	for (int i = 0; i < 10; i++)
		lettcnt += lett[i];
		
	unsigned long long ans = 1;
	
	if (str[0] == '?')
	{
		ans *= 9;
		for (int i = 10; i > 10 - lettcnt; i--)
			ans *= i;
		cout << ans;
		for (int i = 0; i < qcnt-1; i++)
			cout << 0;
	}
	else if (isalpha(str[0]))
	{
		for (int i = 10; i > 10 - lettcnt; i--)
			ans *= i;
		ans = ans / 10 * 9;
		cout << ans;
		for (int i = 0; i < qcnt; i++)
			cout << 0;
	}
	else
	{
		for (int i = 10; i > 10 - lettcnt; i--)
			ans *= i;
		cout << ans;
		for (int i = 0; i < qcnt; i++)
			cout << 0;
	}
	
}