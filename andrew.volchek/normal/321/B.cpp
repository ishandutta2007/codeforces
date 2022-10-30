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

vector < pair < int, bool > > enemy;
vector < int > my;
int n, m;

bool comp(const pair < int, bool > &a, const pair < int, bool > &b)
{
	return a.snd > b.snd || ((a.snd == b.snd) && (a.fst < b.fst));
}



int main(int argc, char **argv)
{
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		char type;
		int str;
		scanf("%c%*c%*c %d\n", &type, &str);
		enemy.pb(mp(str, type=='A'));
	}
	
	for (int i = 0; i < m; i++)
	{
		int str;
		scanf("%d\n", &str);
		my.pb(str);
	}
	
	int ans = 0;
	
	multiset < int > smy;
	multiset < pair < bool , int > > sen;
	
	for (int i = 0; i < n; i++)
		sen.insert(mp(enemy[i].snd,enemy[i].fst));
	for (int i = 0; i < m; i++)
		smy.insert(my[i]);
	int curr_ans = 0;
	while (!sen.empty())
	{
		int need = sen.begin()->snd;
		bool type = sen.begin()->fst;
		set < int > :: iterator it;
		
		if (type)
			it = smy.lower_bound(need);
		else
			it = smy.upper_bound(need);
			
		if (it != smy.end())
		{
			if (type)
				curr_ans += *it - need;
			smy.erase(it);
			set < pair < bool , int > > :: iterator it2 = sen.find(*sen.begin());
			sen.erase(it2);
		}
		else
		{
			//cout << smy.size() << endl;
			break;
		}
	}
	
	if (sen.empty())
	{
		for (set < int > :: iterator it = smy.begin(); it != smy.end(); it++)
			curr_ans += *it;
		ans = curr_ans;
		//cout << curr_ans;
	}
	
	
	sen.clear();
	smy.clear();
	
	curr_ans = 0;
	
	sort(my.begin(), my.end());
	sort(enemy.begin(), enemy.end(), comp);
	int j = 0;
	int cnt = 0;
	int i;
	for (i = int(my.size()) - 1; i >= 0 && j < enemy.size(); i--)
	{
		bool good = false;
		
		while (j < enemy.size())
		{
			if (enemy[j].snd)
			{
				if (my[i] >= enemy[j].fst)
				{
					curr_ans += my[i] - enemy[j].fst;
					j++;
					cnt++;
					good = true;
					break;
				}
				else
					j++;
			}
			else
			{
				if (my[i] > enemy[j].fst)
				{
					j++;
					cnt++;
					good = true;
					break;
				}
				else
					j++;
			}
		}
		
		if (!good)
			break;
	}
	
	if (cnt == n)
	{
		for (;i >= 0; i--)
		{
			curr_ans += my[i];
		}
	}
	
	
	ans = max(ans, curr_ans);
	
	cout << ans;
	
	return 0;
}