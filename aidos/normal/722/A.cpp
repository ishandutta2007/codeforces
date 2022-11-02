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
string x;
string do12(string x){
	int num = (x[0] - '0') * 10 + x[1] - '0';
	int mi = (x[3] - '0') * 10 + x[4] - '0';
	if(mi>59) x[3] = '0';
	if(num>=1 && num <= 12) return x;
	if(num == 0){
		x[0] = '1';
		return x;
	}
	if(x[1] > '0') x[0] = '0';
	else x[0] = '1';
	return x;
}
string do24(string x){
	int num = (x[0] - '0') * 10 + x[1] - '0';
	int mi = (x[3] - '0') * 10 + x[4] - '0';
	if(mi>59) x[3] = '0';
	if(num >= 0 && num < 24) return x;
	x[0] = '0';
	return x;
}
void solve(){
	cin >> n >> x;
	if( n == 24){
		cout << do24(x)<<endl;
	}
	else cout << do12(x)<<endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}