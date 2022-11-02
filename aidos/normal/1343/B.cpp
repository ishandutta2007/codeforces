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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e3 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int a, n;
void solve(){
	cin  >> n;
	if(n % 4 != 0) {
		cout << "NO\n";
		return;
	} 
	cout <<"YES\n";
	for(int i = 1; i <= n/2; i++)
		cout << 2*i << " ";
	for(int i = 1; i < n/2; i++)
		cout << 2*i-1 << " ";
	cout << n+n/2-1 << "\n";
}
int main () {

	int t = 1;
   scanf("%d", &t);
    for(int i=1; i<=t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}