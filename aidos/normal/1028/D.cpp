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
set<int> S, Sa, Sb;
int n;
pii a[400200];
char tmp[333];
int mod = 1000 * 1000 * 1000 + 7;

void check(){
	if(Sa.size() == 0) return;
	if(Sb.size() == 0) return;
	if(*(--Sa.end()) > *Sb.begin()){
		cout << 0 << "\n";
		exit(0);
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s%d", tmp, &a[i].s);
		if(tmp[1] == 'D') a[i].f = 1;
		else a[i].f = 2;
	}
	for(int i = 0; i < n; i++){
		if(a[i].f == 1){
			if(S.count(a[i].s)){
				cout << 0<<"\n";
				return;
			}
			S.insert(a[i].s);
		}else {
			if(S.count(a[i].s) == 0){
				cout << 0 << "\n";
				return;
			}
			S.erase(a[i].s);
		}
	}
	S.clear();
	int ans = 1;
	for(int i = 0; i < n; i++){
		if(a[i].f == 1){
			if(Sa.size() > 0&& *(--Sa.end()) > a[i].s){
				Sa.insert(a[i].s);
			}else if(Sb.size() > 0 && *Sb.begin() < a[i].s){
				Sb.insert(a[i].s);
			}else{
				S.insert(a[i].s);
			}
		}else {
			int type = 0;
			if(Sa.count(a[i].s)){
				if(*(--Sa.end()) > a[i].s){
					cout << 0 << "\n";
					return;
				}
				Sa.erase(a[i].s);
				type=1;
			}else if(Sb.count(a[i].s)){
				if(*Sb.begin() < a[i].s){
					cout << 0 << "\n";
					return;
				}
				Sb.erase(a[i].s);
				type=2;
			}else{
				type = 3;
				S.erase(a[i].s);
			}
			if(type == 3) {
				ans = (ans * 2) % mod;
			}
					while(S.size() > 0 && *S.begin() < a[i].s){
						Sa.insert(*S.begin());
						S.erase(S.begin());
					}
					while(S.size() > 0){
						Sb.insert(*S.begin());
						S.erase(S.begin());
					}
					
				
			
		}
		while(S.size() > 0 && Sa.size() > 0 && *(--Sa.end()) > *S.begin()){
			Sa.insert(*S.begin());
			S.erase(S.begin());
		}
		while(S.size() > 0 && Sb.size() > 0 && *(--S.end()) > *Sb.begin()){
			Sb.insert(*(--S.end()));
			S.erase(--S.end());
		}
		check();
	}
	
	ans = (ans *1ll* (S.size()+1)) % mod;
	cout << ans << "\n";
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