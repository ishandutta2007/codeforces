#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull long long
#define fst first
#define snd second
#define ld long double

vector < char > msg;
char temp[100005];

int main()
{
	int n;
	scanf("%d\n", &n);
	msg.pb('<');
	msg.pb('3');
	for (int i = 0; i < n; i++)
	{
		gets(temp);
		int len = strlen(temp);
		for (int j = 0; j < len; j++)
		{
			msg.pb(temp[j]);
		}
		msg.pb('<');
		msg.pb('3');
	}


	gets(temp);
	int len = strlen(temp);

	int pos = 0;

	for (int i = 0; i < len; i++)
	{
		if (pos == msg.size())
			break;

		if (msg[pos] == temp[i])
			pos++;
	}

	if (pos == msg.size())
		cout << "yes";
	else
		cout << "no";
	
	return 0;
}