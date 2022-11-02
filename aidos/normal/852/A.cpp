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
char c[200200];
string s;
int sum[200200 * 9 * 20];
int step[200200 * 9 * 4];
bool ok[200200];

void print(){
	for(int i = 0; i < n; i++){
		if(i && !ok[i - 1]){
			printf("+");
		}
		printf("%c", s[i]);
	}
	printf("\n");
}

int get(int x){
	if(x == 0) return 0;
	return get(x/10) + x % 10;
}

int  check(int x){
	if(x<10) return 0;
	vector<int> v;
				int j= x;
				while(j > 0) {
					v.pb(j % 10);
					j/=10;
				}
				reverse(all(v));
				int len = v.size();
				--len;
				int found = 0;
				for(int mask = 1; mask < (1<<len); mask++){
					int cur = 0;
					int d = 0;
					for(int i = 0; i < len; i++){
						cur = cur * 10 + v[i];
						if(mask & (1<<i)) {
							d += cur;
							cur = 0;
						}
					}
					d += cur * 10 + v[len];
					if(get(d) < 10){
						return 2;
					}			
				}
	return inf;
}

int go(int x){
	if(x < 10){
		cout << x<<endl;
		return x;
	}
	int nmask = -1,val = -1;
	vector<int> v;
				int j= x;
				while(j > 0) {
					v.pb(j % 10);
					j/=10;
				}
				reverse(all(v));
				int len = v.size();
				--len;
				int found = 0;
				for(int mask = 1; mask < (1<<len); mask++){
					int cur = 0;
					int d = 0;
					for(int i = 0; i < len; i++){
						cur = cur * 10 + v[i];
						if(mask & (1<<i)) {
							d += cur;
							cur = 0;
						}
					}
					d += cur * 10 + v[len];
					if(d < 10){
						val = d;
						nmask = mask;
						break;
					}
					if(get(d) < 10){
						val = d;
						nmask = mask;
					}			
				}
						for(int i = 0; i <= len; i++){
							if(i && (nmask&(1<<(i-1)))) cout << "+";
							cout<<v[i];
						}
						cout << endl;
						
					
	return val;

}
void solve(){
	scanf("%d%s", &n, c);
	s = c;

	while(1){
		int tt = 0;
		for(int i = 0; i < n; i++)
			ok[i] = 0;
	   	for(int i = 0; i < n; ){
	   		int g = min(rand() % 2 + 1, n - i);
	   		if(g == 2) {
	   			tt += (s[i] - '0') * 10 + s[i+1] - '0';
	   			ok[i] =1;
	   		}else{
	   			tt += s[i] - '0';
	   		}
	   		i += g;
	   	}
	   	if(check(tt) < 3){
	   		print();
	   		tt = go(tt);
	   		tt = go(tt);
	   		return;
	   	}
    }
	return;
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