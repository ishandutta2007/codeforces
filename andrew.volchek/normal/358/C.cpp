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

const int maxn = 100005;
int a[maxn];
int popCnt[maxn];
int popFrom[maxn];
int pushTo[maxn];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int cnt[3] = {0, 0, 0,};

	priority_queue < pair < int, int > > q;

	// 1 - st
	// 2 - q
	// 3 - dq begin
	// 4 - dq end
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			q.push(mp(a[i], i));
			/*int ind = 0;
			if (cnt[ind] > cnt[1])
				ind = 1;
			if (cnt[ind] > cnt[2])
				ind = 2;
			cnt[ind]++;*/
			//pushTo[q.top().snd] = ind + 1;
		}
		else
		{
			/*popCnt[i] = (cnt[0] != 0) + (cnt[1] != 0) + (cnt[2] != 0);
			popFrom[i] = ((1 << 0) * (cnt[0] != 0)) | ((1 << 1) * (cnt[1] != 0)) | ((1 << 2) * (cnt[2] != 0));
			
			for (int j = 0; j < 3; j++)
			{
				if (cnt[j] > 0)
				{
					pushTo[q.top().snd] = j + 1;
					q.pop();
				}
			}

			for (int j = 0; j < 3; j++)
				cnt[j] = max(0, cnt[j] - 1);*/
			popCnt[i] = min(3, (int)q.size());

			for (int j = 0; j < popCnt[i]; j++)
			{
				pushTo[q.top().snd] = j + 1;
				q.pop();
			}

			while (!q.empty())
	{
		pushTo[q.top().snd] = 4;
		q.pop();
	}
		}
	}

	

	
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			if (pushTo[i] == 1)
			{
				cout << "pushStack" << endl;
			}
			else if (pushTo[i] == 2)
			{
				cout << "pushQueue" << endl;
			}
			else if (pushTo[i] == 3)
			{
				cout << "pushFront" << endl;
			}
			else
			{
				cout << "pushBack" << endl;
			}
		}
		else
		{
			cout << popCnt[i];

			if (popCnt[i] >= 1)
				cout << " popStack";
			if (popCnt[i] >= 2)
				cout << " popQueue";
			if (popCnt[i] >= 3)
				cout << " popFront";
			cout << endl;
		}
	}
	
	cin >> n;
	
	return 0;
}