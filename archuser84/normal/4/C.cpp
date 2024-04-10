#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 33;
const int tableSize = 26 * 26 * 26;
const int ind[3] = { 1,30,17 };

struct cell
{
	char key[N] = {};
	int data = 1;
	cell(char* s)
	{
		Loop(i, 0, N)
			key[i] = s[i];
	}
	cell* next = NULL;
};

cell* Table[tableSize] = {};

bool strEql(char* s, char* t)
{
	for (int i = 0;; i++)
	{
		if (s[i] != t[i])
			return false;
		if (s[i] == '\0')
			break;
	}
	return true;
}

int Hash(char* s)
{
	int ans = 0;
	int size = strlen(s);
	int k = 1;
	for (int x : ind)
	{
		ans += (s[x % size] - 'a') * k;
		k *= 26;
	}
	return ans;
}


int getValue(char* s)
{
	int h = Hash(s);
	if (Table[h] == NULL)
	{
		Table[h] = new cell(s);
		return 0;
	}
	cell* k = Table[h];
	while (true)
	{
		if (strEql(k->key, s))
			return k->data++;
		if (k->next == NULL)
		{
			k->next = new cell(s);
			return 0;
		}
		k = k->next;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s[N];
		cin >> s;
		int k = getValue(s);
		if (k == 0)
			cout << "OK\n";
		else
			cout << s << k << '\n';
	}
}