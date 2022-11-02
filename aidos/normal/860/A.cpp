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
std::vector<string> v;
string a = "aeiou";

int good(string &x){
	if(x.size() < 3) return 1;
	int n = x.size();
	if(x[n-1] == x[n-2] && x[n-1] == x[n-3]) return 1;
	for(int i = 1; i <= 3; i++){
		for(int j = 0; j < a.size(); j++)
			if(x[n-i] == a[j]) return 1;
	}
	return 0;
}
void solve(){
	cin >>s;
	for(int  i = 0; i < s.size(); ){
		string t = "";
		while(i < s.size()){
			t += s[i];
			if(!good(t)){
				t.pop_back();
				break;
			}
			i++;
		}
		v.pb(t);
	}
	for(int i = 0; i < v.size(); i++){
		if(i) cout << ' ';
		cout << v[i];
	}
	cout << endl;
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