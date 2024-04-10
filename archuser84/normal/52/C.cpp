#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const ll max_n = 200'000 + 10;
const ll inf = 1'000'000'000'000;
struct node {
	ll lazy, mini;
} seg[4 * max_n];
ll n;


void relax(ll b, ll e, ll node) {
	ll mid = (b + e) / 2;
	ll ln = node * 2, rn = node * 2 + 1;
	ll x = seg[node].lazy;
	seg[ln].lazy += x;
	seg[rn].lazy += x;
	seg[ln].mini += x;
	seg[rn].mini += x;
	seg[node].lazy = 0;

}

void add(ll l, ll r, ll cnt,ll node = 1, ll b = 0, ll e = n) {
	if(b >= r || l >= e) {
		return;
	}
	if(l <= b && e <= r) {
        	seg[node].mini += cnt;
        	seg[node].lazy += cnt;
        	return;
    	}
	relax(b, e, node);
	ll mid = (b + e) / 2;
	ll ln = 2 * node, rn = 2 * node + 1;
	add(l, r, cnt, ln, b, mid);
	add(l, r, cnt, rn, mid, e);
	seg[node].mini = min(seg[ln].mini, seg[rn].mini);
}


ll get(ll l, ll r, ll node = 1, ll b = 0, ll e = n) {
	if(b >= r || l >= e) {
		 return inf;
	 }
    	if(l <= b && e <= r) {
        	return seg[node].mini;
	}
	relax(b, e, node);
	ll mid = (b + e) / 2;
	ll ln = 2 * node, rn = 2 * node + 1;
	int x = min(get(l, r, ln, b, mid), get(l, r, rn, mid, e));
	return x;
}

string s;
bool input(ll& a, ll& b, ll& c)
{
    cin >> ws;
    int x[3]={};
    int y[3]={1,1,1};
    getline(cin, s);
    int k = 0;
    int n = s.size();
    Loop(i,0,n)
    {
        if(s[i] == ' ')
            {++k; continue;}
        if(s[i] == '-')
            {y[k] = -1; continue;}
        x[k] *= 10;
        x[k] += s[i]-'0';
    }
    a=x[0]*y[0];
    b=x[1]*y[1];
    c=x[2]*y[2];
    return k==2;
}

int main() {
    cin.tie(0);
	scanf("%I64d", &n);
	for (ll i = 0; i < n; ++i) {
		ll a;
		scanf("%I64d", &a);
		add(i, i + 1, a, 1, 0, n);
	}
	ll q;
	scanf("%I64d", &q);
	while (q--) {
		ll l, r, cnt;
		char c;
		if (!input(l, r, cnt)) {
			if(l > r) {
                		printf("%I64d\n", min(get(l , n) , get(0 , r+1)));
           		} else {
                		printf("%I64d\n", get(l , r+1));
            		}
		} else {
			if(l > r) {
             			add(l , n , cnt, 1, 0, n);
                		add(0 , r+1 , cnt, 1, 0, n);
           		} else {
               			add(l , r+1 , cnt, 1, 0, n);
           		}
		}

	}

	return 0;
}