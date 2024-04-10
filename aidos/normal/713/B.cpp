#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n;
int l, r;
int resx1, resx2, resy1, resy2;

int cnt = 0;

int ask(int x1, int y1, int x2, int y2){
	cout << "? " << x1 << " "<< y1 << " "<< x2 << " " << y2 << endl;
	cnt++;
	int ans;
	cin >> ans;
	return ans;	
}

void out(pair<pii, pii>a, pair<pii, pii> b){
	cout << "!";
	cout << " " << a.f.f << " " << a.f.s << " "<< a.s.f << " " << a.s.s;
	a = b;
	cout << " " << a.f.f << " " << a.f.s << " "<< a.s.f << " " << a.s.s;
	cout << endl;
	exit(0);
}

pair<pii, pii> get(int x1, int y1, int x2, int y2, bool ok){
	int l = x1, r = x2;
	while(l <= r){
		int mid = (l + r)>>1;
		if(ask(x1, y1, mid, y2)){
			r = mid-1;
			x2 = mid;
		}
		else l = mid+1;
	}
	l = x1, r = x2;
	while(l <= r){
		int mid = (l + r)>>1;
		if(ask(mid, y1, x2, y2)){
			l = mid+1;
			x1 = mid;
		}
		else r = mid-1;
	}
	l = y1, r = y2;
	while(l <= r){
		int mid = (l + r)>>1;
		if(ask(x1, y1, x2, mid)){
			r = mid-1;
			y2 = mid;
		}
		else l = mid+1;
	}
	l = y1, r = y2;
	while(l <= r){
		int mid = (l + r)>>1;
		if(ask(x1, mid, x2, y2)){
			l = mid+1;
			y1 = mid;
		}
		else r = mid-1;
	}
	return mp(mp(x1, y1), mp(x2, y2));
}
void solve(){
	cin >> n;                   
	l = 1, r = n-1;
	while(l <= r){
		int mid = (l + r) >> 1;
		int ans1 = ask(1, 1, mid, n);
		int ans2 = ask(mid+1, 1, n, n);
		if(ans1 + ans2 == 0) break;
		if(ans1 == 2){
			r = mid-1;
		}else if(ans2 == 2){
			l = mid+1;
		}
		else if(ans1==ans2){
			out(get(1, 1, mid, n, 1), get(mid+1, 1, n, n, 0));
			return;
		}
		else if(ans1 > ans2){
			r = mid-1;
		}
		else l = mid+1;
	}
	l = 1, r = n-1;
	while(l <= r){
		int mid = (l + r) >> 1;
		int ans1 = ask(1, 1, n, mid);
		int ans2 = ask(1, mid+1, n, n);
		if(ans1 + ans2 == 0) break;
		if(ans1 == 2){
			r = mid-1;
		}else if(ans2 == 2){
			l = mid+1;
		}
		else if(ans1==ans2){
			out(get(1, 1, n, mid, 1), get(1, mid+1, n, n, 0));
			return;
		}
		else if(ans1 > ans2){
			r = mid-1;
		}
		else l = mid+1;
	}
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}