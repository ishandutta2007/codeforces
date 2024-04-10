#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

#define maxn 200200

int r[maxn];
pair<pi,int> t[maxn];

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	fore(i,n) scanf("%d", &r[i]);
	fore(i,m) scanf("%d%d%d", &t[i].x.x, &t[i].x.y, &t[i].y);
	sort(t,t+m);
	int64 res = 0;
	fore(i,m)
	{
		t[i].x.x--;
		t[i].x.y--;
		res += t[i].y;
	}
	int cur = 0;
	multiset<pi> all;
	for(int i = 0; i < n; i++)
	{
		while(cur < m && t[cur].x.x == i)
		{
			all.insert(mp(t[cur].x.y, t[cur].y));
			cur++;
		}
		while(all.size() > 0 && all.begin() -> x < i)
			all.erase(all.begin());
		while(r[i] > 0 && all.size() > 0)
		{
			pi p = *all.begin();
			all.erase(all.begin());
			int flow = min(r[i], p.y);
			res -= flow;
			p.y -= flow;
			r[i] -= flow;
			if(p.y > 0) all.insert(p);
		}
	}
	cout << res << endl;
}