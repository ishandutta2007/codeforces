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


int n, k;
int a4, a2;
int cnt[10100];
vector<int> v;
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		a2 += 2, a4++;
	int bad = 0;
	for(int i = 0, x; i < k; i++){
		cin>> x;
		int k = min(x/4, a4);
		a4 -= k;
		x -= k * 4;
		if(x > 0) v.pb(x);
	}
	sort(all(v));
	reverse(all(v));
	for(int i = 0; i < v.size(); i++){
		int x = v[i];
		if(a4 > 0){
			if(x == 3){
				a4--;
				continue;
			}
			if(x == 2){
				a4--;
				bad++;
				continue;
			}
			a4--;
			a2++;
			continue;
		}
		int k = min(x/2, a2);
		a2 -= k;
		x -= 2 * k;
		if(x == 0) continue;
		if(x == 1 && bad > 0) {
			bad--;
			continue;
		}
		if(x == 1 && a2 > 0){
			a2--;
			continue;
		}
		if(x <= bad){
			bad-=x;
			continue;
		}
		cout <<"NO"<<endl;
		return;
	}
	cout << "YES" << endl;

}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}