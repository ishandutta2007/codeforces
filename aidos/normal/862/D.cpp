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
int rev;
vector<int> a;


int get(){
	cout << "? ";
	for(int i = 0; i < n; i++)
		cout << (a[i]^rev);
	cout << endl;
	int x;
	cin  >> x;
	return n-x;
}

#define x1 sfdgsfgsdfg

void out(int x, int y){
	if(!rev) swap(x, y);
	cout <<"! ";
	cout << x << " "<< y << endl;
	exit(0);
}
void go(int l, int r, int sum, int D){
	if(l == r){
		out(1, r + 1);
	}
	int mid = (l + r)>>1;
	for(int i =l; i <= mid; i++)
		a[i] = 1;
	for(int i = mid + 1; i <= r; i++)
		a[i] = 0;
	int len = r - l + 1;
	int CC = get() - D;
	int BB = sum;
	int AA = len - BB;
	//x0 + y0 = BB
	//x1 + y1 = AA
	//x1 + y0 = CC
	//y0 + y1 = r - mid;
	//x1 + y0 + y0 + y1 = CC + r - mid;
	//y0 * 2 = CC + r - mid - AA
	int y0 = (CC + r - mid - AA)/2;
	int x1 = CC - y0;
	if(y0>0){
		go(mid + 1, r, y0, D + x1);
	}
	else {
		go(l, mid, BB - y0, D + y0);
	}
}
void solve(){
	cin >> n;              
	for(int i = 0 ; i < n; i++){
		a.pb(0);
	}
	int x = get();
	a[0] = 1;
	int y = get();
	if(x > y) {
		a[0] = 1;
		rev = 1;
		go(1, n-1, n-x, 1);
	}
	else{
		go(1, n-1, x, 1);
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