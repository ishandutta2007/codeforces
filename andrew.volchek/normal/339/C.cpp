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
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double


int pr[1005][11][11];
int good[11];

int main(int argc, char **argv)
{
	for (int i = 0; i < 10; i++)
	{
		char ch;
		scanf("%c", &ch);
		good[i+1] = ch == '1';
	}
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 11; j++)
			for (int h = 0; h < 11; h++)
			pr[i][j][h]= 0;
				
	queue < pair < int, pair < int , int > > > q;
	q.push(mp(0, mp(0, 0)));

	while (!q.empty())
	{
		pair < int, pair < int , int > > curr = q.front();
		q.pop();
		
		
		if (curr.fst == m)
			break;
			
		for (int i = 1; i <= 10; i++)
		{
			if (!good[i] || i == curr.snd.snd)
				continue;
			
			if (i <= curr.snd.fst)
					continue;
			
			if (pr[curr.fst+1][i-curr.snd.fst][i] == 0)
			{
				pr[curr.fst+1][i-curr.snd.fst][i] = 1;
				q.push(mp(curr.fst+1, mp(i-curr.snd.fst, i)));
			}
		}
	}
	
	vector < int > ans;
	int curr = m;
	int currDiff = 0;
	
	for (int j = 1; j <= 10; j++)
	for (int i = 1; i <= 10; i++)
	{
		if (pr[m][i][j] != 0)
			currDiff = i;
	}
	
	if (currDiff == 0)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		
		vector < int > ans;
		int prv = 0;
		while (curr)
		{
			int idx = 0;
			for (int i = 1; i <= 10; i++)
				if (prv != i && pr[curr][currDiff][i] == 1)
					idx = i;
			prv = idx;
			if (idx == 0)
			{
				break;
			}
			
			ans.pb(idx);
			currDiff = idx - currDiff;
			curr--;
		}
		
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	} 

	
	return 0;
}