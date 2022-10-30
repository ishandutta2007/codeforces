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

const int maxn = 100005;
const int inf = 1000000000;
const ll mod = 1000000007;


int n;
int a[maxn];
int next[maxn];
int q[2][maxn];
int cnt = 0;

int main(int argc, char **argv)
{
	scanf("%d", &n);

		
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
		
	for (int i = 0; i < n-1; i++)
		next[i] = i+1;
	next[n-1] = -1;
	
	for (int i = 0; i < n-1; i ++)
		q[0][i] = i;
		
	cnt = n-1;
		
	
	int ans = 0;
	
	while (true)
	{
		bool any = false;
		int ncnt = 0;
		int was = -2;
		
		for (int i = 0; i < cnt; i++)
		{
			int curr = q[ans&1][i];
			if (curr < was || curr == -1)
				continue;
			if (next[curr] == -1)
				continue;
			if ( a[curr] > a[next[curr]])
			{
				any = true;
				q[1-(ans&1)][ncnt++] = curr;
			}
			
			while (curr != -1 && a[curr] > a[next[curr]]) curr = next[curr];
			next[q[ans&1][i]] = curr == -1 ? -1 : next[curr];
			was = curr;
		}
		
		if (any == false)
			break;
		
		cnt = ncnt;
		ans++;
	}
	cout << ans;
	
	return 0;
}