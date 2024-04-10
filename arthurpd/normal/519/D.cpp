#include <stdio.h>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

char s[112345];
long long a[112345];
int v[30];
map<long long,int> rdm[30];

int main(void)
{
	int n;
	for(int i = 0; i < 26; i++)
		scanf("%d", &v[i]);
	scanf("%s", s);
	n = strlen(s);
	a[0] = v[s[0] - 'a'];
	for(int i = 1; i < n; i++)
		a[i] = v[s[i] - 'a'] + a[i-1];
	long long ans = 0;
	rdm[s[0] - 'a'][a[0]]++;
	for(int i = 1; i < n; i++)
	{
		ans += rdm[s[i] - 'a'][a[i-1]];
		rdm[s[i] - 'a'][a[i]]++;
	}
	cout << ans << endl;
}