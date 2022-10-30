#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define x first
#define y second

bool between(pii a, pii b, pii c) {
	return min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x) &&
		   min(b.y, c.y) <= a.y && a.y <= max(b.y, c.y); 
}

const int INF = 1e9;

bool valid(int x) {
	return 0 <= x && x <= INF;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pii school;
    cin >> school.fs >> school.sc;
    vector <pii> a(n);
    forn (i, 0, n)	
    	cin >> a[i].fs >> a[i].sc;
    int ans = 0;
    pii ans_cords;
    forn (dx, -1, 2) {
    	forn (dy, -1, 2) {
    		int cnt = 0;
    		pii t = {school.x + dx, school.y + dy};
    		if (t.x == school.x && t.y == school.y)
    			continue;
    		if (!valid(t.x) || !valid(t.y))
    			continue;
    		forn (i, 0, n)
    			if (between(t, school, a[i]))
    				cnt++;
    		//cout << t.x << " " << t.y << ": " << cnt << "\n";
    		if (cnt >= ans) {
    			ans = cnt;
    			ans_cords = t;
    		}
    	}
    }
    cout << ans << "\n";
    cout << ans_cords.x << " " << ans_cords.y;
    return 0;
}