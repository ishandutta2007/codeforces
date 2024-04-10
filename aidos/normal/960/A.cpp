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

string s;
void solve(){
	cin >> s;
	int i = 0;
	while(i < s.size() && s[i] == 'a') i++;
	int j = i;
	while(j < s.size() && s[j] == 'b') j++;
	int k = j;
	while(k < s.size() && s[k] == 'c') k++;
	if(k != s.size() || i == j || j == k || (k-j!=j-i && k-j != i) || i == 0){
		printf("NO\n");
	}else printf("YES\n");
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