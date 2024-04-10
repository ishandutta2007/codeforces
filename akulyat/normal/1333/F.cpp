#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
bool viv = false;
vector<ll> v, p;

vector<long long> erat(long long last)
{
vector<ll> bad;
vector<long long> r;
for (long long i = 0; i < last + 10; i++)
    bad.push_back(1);
for (long long i = 2; i <= last; i++)
    if (bad[i] == 1)
        {
        long long j = 1;
        while (j * i <= last)
            {
            if (bad[j * i] == 1)
	            bad[j * i] = i;
            j++;
            }
        r.push_back(i);
        }
    v = bad;
return r;
}


void solve() {
	p = erat(ml);
	cin >> n;
	vector<ll> ans;
	for (int i = 1; i <= n; i++)
		ans.push_back(i / v[i]);
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}