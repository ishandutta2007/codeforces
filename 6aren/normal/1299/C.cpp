#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 1000005;
const double EPS = 1e-10;

int read_int(){
	char r;
	bool start=false,neg=false;
	int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

int a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<pair<double, int>> s;
    s.insert({a[n], 1});
    for (int i = n - 1; i >= 1; i--) {
        double cur = a[i];
        int cnt = 1;
        while (!s.empty() && cur / cnt > s.begin() -> x - EPS) {
            cur += s.begin() -> x * s.begin() -> y;
            cnt += s.begin() -> y;
            auto it = s.begin();
            s.erase(it);
        }
        s.insert({cur / cnt, cnt});
        //for (auto u : s) cout << i << ' ' << u.x << ' ' << u.y << endl;
    }
    for (auto u : s) {
        for (int i = 1; i <= u.y; i++) {
            printf("%.9f\n", u.x);
        }
    }
    return 0;
}