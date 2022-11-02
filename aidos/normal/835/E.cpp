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

int n, x, y;
int bi = 0;
int lg = 0;

int out(vector<int> v){
	cout <<"? " << v.size();
	forit(it, v){
		cout << " " << (*it) + 1;
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
int get(vector<int> v){
	int res = 0;
	for(int i = 0; i < v.size(); i++)
		res ^= x;
	return res;
}
void solve(){
	cin >> n >> x >> y;
	while((1<<lg) < n) lg++;
	lg--;
	while(!((x^y) & (1<<bi))){
		bi++;
	}
	int ans = 0;
	for(int i = 0; i < n-2; i++)
		ans ^= x;
	int d = -1;
	int same = 0;
	for(int i = 0; i <= lg; i++){
		vector<int> v;
		for(int j = 0; j < n; j++){
			if(j & (1<<i)) v.pb(j);  
		}
		int res = out(v);
		if(res != get(v)){
			same |= (1<<i);
			d = i;
		}
	}
	vector<int> res;
	for(int i = 0; i < n; i++){
		if(i&(1<<d)) res.pb(i);
	}
	while(res.size()>1){
		vector<int> nres;
		random_shuffle(all(res));
		while(res.size() > nres.size()){
			nres.pb(res.back());
			res.pop_back();
		}
		int d = out(res);
		if(d == get(res)){
			res = nres;
		}
	}
	int A = res[0];
	int B = res[0] ^ same;
	if(A > B) swap(A, B);
	cout << "! " << A + 1 << " " << B + 1<<endl;
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