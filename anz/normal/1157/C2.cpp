#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}


int n;
int a[200001];

int fLeft[200001];
int fRight[200001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int minLen = 0;
	int curMin = 987654321;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < curMin)
		{
			minLen++;
			curMin = a[i];
		}
		else
		{
			minLen = 1;
			curMin = a[i];
		}

		fRight[i] = minLen;
	}

	minLen = 0;
	curMin = 987654321;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < curMin)
		{
			minLen++;
			curMin = a[i];
		}
		else
		{
			minLen = 1;
			curMin = a[i];
		}

		fLeft[i] = minLen;
	}

	int lptr = 0;
	int rptr = n - 1;

	int result = 0;
	string s = "";
	int curMax = 0;
	while (lptr <= rptr)
	{
		int cLeft = a[lptr];
		int cRight = a[rptr];

		bool bl = cLeft > curMax ? true : false;
		bool br = cRight > curMax ? true : false;

		if (bl && br)
		{
			if (cLeft < cRight)
			{
				lptr++;
				result++;
				s += "L";
				curMax = cLeft;
			}
			else if (cLeft > cRight)
			{
				rptr--;
				result++;
				s += "R";
				curMax = cRight;
			}
			else
			{
				if (fLeft[lptr] > fRight[rptr])
				{
					lptr++;
					result++;
					s += "L";
					curMax = cLeft;
				}
				else
				{
					rptr--;
					result++;
					s += "R";
					curMax = cRight;
				}
			}
		}
		else if (bl)
		{
			lptr++;
			result++;
			s += "L";
			curMax = cLeft;
		}
		else if (br)
		{
			rptr--;
			result++;
			s += "R";
			curMax = cRight;
		}
		else break;
	}

	cout << result << endl << s;
}