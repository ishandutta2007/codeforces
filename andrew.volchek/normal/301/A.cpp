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

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

vector < int > pos, neg;
int n;

int main(int argc, char **argv)
{
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n*2-1; i++)
	{
		int x;
		cin >> x;
		sum += x;
		if (x >= 0)
			pos.pb(x);
		else
			neg.pb(x);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	while (n <= neg.size() && neg.size() % 2)
	{
		for (int j = 0; j < n; j++)
		sum += -neg[j] * 2;
		for (int j = 0; j < n; j++)
		neg.erase(neg.begin());
	}
	
		for (int i = n*2-2; i >= 0; i -= 2-(n&1))
		{
			if (neg.size() == i)
			{
				for (int j = 0; j < neg.size(); j++)
				sum += -neg[j] * 2;
				break;
			}
			else if (int(neg.size()) -1 == i)
			{
				int sum1 = sum;
				int sum2 = sum;
				for (int j = 0; j < neg.size()-1; j++)
				sum1 += -neg[j] * 2;
				
				
				if (neg.size() != 2*n-1 && pos.size())
				{
				for (int j = 0; j < neg.size(); j++)
				sum2 += -neg[j] * 2;
				
				if (pos.size())
				sum2 = sum2 - pos[0]*2;
				}
				
				
				sum = max(sum1,sum2);
				break;
			}
		}
	
	
	
	cout << sum;
	return 0;
}