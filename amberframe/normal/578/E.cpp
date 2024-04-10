#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef long long LL ;
const int maxn = 1e5 + 5;
const int mod = 998244353;

set<int> l, r;
int n, cntl, cntr;
char str[maxn];
vector < int > track;
vector < vector<int> > ll, rr, lr, rl;

int main()
{
	#ifdef FILE_TESTn
		freopen("walking.in", "r", stdin);
	#endif
	
	scanf("%s", str + 1);
	n = strlen(str + 1);
	repi(n) str[i] == 'L' ? (++cntl, l.insert(i)) : (++cntr, r.insert(i));
	
	int ans = -1;
	while (!l.empty() || !r.empty())
	{
		int cur = l.empty() ? *r.begin() : ( r.empty() ? *l.begin() : min(*l.begin(), *r.begin()) );
		track.clear(); track.pb(cur); ++ans;
		while (true)
		{
			if (str[cur] == 'L')
			{
				l.erase(cur);
				auto it = r.upper_bound(cur);
				if (it == r.end()) break;
				cur = *it;
			}
			else {
				r.erase(cur);
				auto it = l.upper_bound(cur);
				if (it == l.end()) break;
				cur = *it;
			}
			track.pb(cur);
		}
		if (str[track[0]] == 'L')
			str[cur] == 'L' ? ll.pb(track) : lr.pb(track);
		else
			str[cur] == 'L' ? rl.pb(track) : rr.pb(track);
	}
	
	printf("%d\n", ans);
	if (cntl > cntr)
	{
		for (unsigned j = 0 ; j < lr.size() ; ++j)
			print(lr[j]);
		for (unsigned j = 0 ; j < rr.size() ; ++j)
			{print(ll[j]); print(rr[j]);}
		print(ll[rr.size()]);
		for (unsigned j = 0 ; j < rl.size() ; ++j)
			print(rl[j]);
	}
	if (cntl < cntr)
	{
		for (unsigned j = 0 ; j < rl.size() ; ++j)
			print(rl[j]);
		for (unsigned j = 0 ; j < ll.size() ; ++j)
			{print(rr[j]); print(ll[j]);}
		print(rr[ll.size()]);
		for (unsigned j = 0 ; j < lr.size() ; ++j)
			print(lr[j]);
	}
	if (cntl == cntr)
	{
		if (rl.empty()) {
			for (unsigned j = 0 ; j < lr.size() ; ++j)
				print(lr[j]);
			for (unsigned j = 0 ; j < rr.size() ; ++j)
				{print(ll[j]); print(rr[j]);}
		}
		else if (lr.empty()) {
			for (unsigned j = 0 ; j < rr.size() ; ++j)
				{print(rr[j]); print(ll[j]);}
			for (unsigned j = 0 ; j < rl.size() ; ++j)
				print(rl[j]);
		}
		else {
			int p = lr[0].size() - 1;
			int q = rl[0].size() - 1;
			if (lr[0][p] > rl[0][q])
			{
				for (unsigned j = 0 ; j < rr.size() ; ++j)
					{print(ll[j]); print(rr[j]);}
				for (unsigned j = 0 ; j < p ; ++j)
					printf("%d ", lr[0][j]);
				for (unsigned j = 0 ; j < rl.size() ; ++j)
					print(rl[j]);
				printf("%d ", lr[0][p]);
				for (unsigned j = 1 ; j < lr.size() ; ++j)
					print(lr[j]);
			}
			else {
				for (unsigned j = 0 ; j < rr.size() ; ++j)
					{print(rr[j]); print(ll[j]);}
				for (unsigned j = 0 ; j < q ; ++j)
					printf("%d ", rl[0][j]);
				for (unsigned j = 0 ; j < lr.size() ; ++j)
					print(lr[j]);
				printf("%d ", rl[0][q]);
				for (unsigned j = 1 ; j < rl.size() ; ++j)
					print(rl[j]);
			}
		}
	}
	return 0;
}