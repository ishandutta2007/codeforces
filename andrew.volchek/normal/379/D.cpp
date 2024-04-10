#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

ll cnt[4][4];


int getMax(char c1, char c2, int len)
{	
	if (len == 2 && c1 == 'A' && c2 == 'C')
		return 1;
	else if (len == 2)
		return 0;
		
	
	
	int cnt = 0;
	if (c1 == 'A')
	{
		cnt++;
		len -= 2;
	}
	else
	{
		len--;
	}
	
	if (len >= 2)
	{
		if (c2 == 'C')
		{
			cnt++;
			len -=2;
		}
		else
		{
			len--;
		}
		
		cnt += len / 2;
	}
	else
	{
		
	}
	
	return cnt;
}

int k, x, n, m;

void printAns(char i1, char i2, int cnt, int len)
{
	char str[305];
	
	str[0] = i1;
	str[len-1] = i2;
	
	int l = 1, r = len-2;
	
	if (cnt && i1 == 'A')
	{
		str[l] = 'C';
		cnt--;
		l += 1;
	}
	
	if (cnt && i2 == 'C')
	{
		str[r] = 'A';
		cnt--;
		r -= 1;
	}
	
	for (int i = 0; i < cnt; i++)
	{
		str[l] = 'A';
		str[l+1] = 'C';
		l+=2;
	}
	
	for (int i = l; i <= r; i++)
		str[i] = 'B';
		
	for (int i = 0; i < len; i++)
		printf("%c", str[i]);
	printf("\n");
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	cin >> k >> x >> n >> m;
	
	vector < pair < int, int> > v;
	vector < pair < ll, ll > > v2;
	vector < pair < ll, ll > > v3;
	vector < int > v4;
	v2.pb(mp(1, 0));
	v2.pb(mp(0, 1));
	v.pb(mp(0, 1));
	v.pb(mp(2, 3));
	v3.pb(mp(0, 0));
	v3.pb(mp(0, 0));
	v4.pb(0);
	v4.pb(0);
	

	
	
	
	for (int i = 2; i < k; i++)
	{
		pair < int, int > np;
		pair < ll, ll > np2;
		np2.fst = v2[i-2].fst + v2[i-1].fst;
		np2.snd = v2[i-2].snd + v2[i-1].snd;
		v2.pb(np2);
		
		np.fst = v[i-2].fst;
		np.snd = v[i-1].snd;
		v.pb(np);
		
		pair < ll, ll > np3;
		np3.fst = v3[i-2].fst + v3[i-1].fst;
		np3.snd = v3[i-2].snd + v3[i-1].snd;
		if (v[i-2].snd == 1 && v[i-1].fst == 2)
			np3.fst++;
		if (v[i-2].snd == 3 && v[i-1].fst == 0)
			np3.snd++;
		v3.pb(np3);
		
		int nv4 = v4[i-2] + v4[i-1];
		if (v[i-2].snd == 3 && v[i-1].fst == 2)
			nv4++;
		v4.pb(nv4);
	}
	

	
	
	for (char i1 = 'A'; i1 < 'D'; i1++)
		for (char i2 = 'A'; i2 < 'D'; i2++)
			for (char i3 = 'A'; i3 < 'D'; i3++)
				for (char i4 = 'A'; i4 < 'D'; i4++)
				{
					if (n == 1 && i1 != i2)
						continue;
					if (m == 1 && i3 != i4)
						continue;
					
					ll currCnt = 0;
					if (i2 == 'A' && i3 == 'C')
						currCnt += v3.back().fst;
						
					if (i4 == 'A' && i1 == 'C')
					{
						currCnt += v3.back().snd;
					}
					
					if (i4 == 'A' && i3 == 'C')
						currCnt += v4.back();
					
					//cerr << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
					//cerr << currCnt << endl;
					
					if (currCnt > x)
					{
						continue;
					}
					
					ll need = x - currCnt;
					
					ll max1 = 0, max2 = 0;
					
					if (n == 1)
						max1 = 0;
					else
						max1 = getMax(i1, i2, n);
						
					if (m == 1)
						max2 = 0;
					else
						max2 = getMax(i3, i4, m);
						
						
					ll min1, min2;
					
					if (n == 2 && i1 == 'A' && i2 == 'C')
						min1 = 1;
					else
						min1 = 0;
						
					if (m == 2 && i3== 'A' && i4 == 'C')
						min2 = 1;
					else
						min2 = 0;
					
						
					ll cnt1 = v2.back().fst;
					ll cnt2 = v2.back().snd;
					
					for (int i = min1; i <= max1; i++)
					{
						for (int j = min2; j <= max2; j++)
						{
							if (need == (cnt1 * i + cnt2 * j))
							{
								printAns(i1, i2, i, n);
								printAns(i3, i4, j, m);
								return 0;
							}
						}
					}
				}
	
	puts("Happy new year!");
	
	
	return 0;
}