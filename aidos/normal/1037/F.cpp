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

int a[1000100];
int n, k;

void rec(vector<int> a, int k){
	if(a.size()<k) return;
	vector<int> b;
	for(int i = 0; i <= a.size()-k;i++){
		b.pb(a[i+k-1]);
	}
	for(int i = 0; i < b.size(); i ++){
		cout << b[i] << " ";
	}
	cout << "\n";
	rec(b, k);
}
int b[1000100];
int mod = 1000 * 1000 * 1000 + 7;
int l[1000100];
int r[1000100];
int solve2(vector<int> d){
	if(d.size() == 0) return 0;
	ll ans = 0;
	vector<int> st;
	for(int i = 0; i < d.size(); i++){
		while(st.size() > 0 && d[st.back()] < d[i]){
			st.pop_back();
		}
		if(st.size() == 0) l[i] = -1;
		else l[i] = st.back();
		st.pb(i);
	}
	st.clear();
	
	for(int i = d.size()-1; i >=0; i--){
		while(st.size() > 0 && d[st.back()] <= d[i]){
			st.pop_back();
		}
		if(st.size() == 0) r[i] = d.size();
		else r[i] = st.back();
		st.pb(i);
	}
	for(int i = 0; i < d.size(); i++){
		ans = (ans + (i-l[i] ) * 1ll * d[i] % mod * (r[i] - i) % mod) % mod;
	}
	return ans;
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	vector<int> st;
	for(int i = n-1; i >= 0; i--){
		while(st.size() > 0 && a[st.back()] <= a[i]){
			st.pop_back();
		}
		st.pb(i);
		if(i+k<=n){
			int l = 0, r = st.size()-1;
			int x = -1;
			while(l<=r){
				int mid = (l+r)>>1;
				if(st[mid] >= i+k){
					l = mid+1;
				}
				else{
					x = mid;
					r = mid-1;
				}
			}
			b[i] = a[st[x]];
		}
	}
	ll ans = 0;
	for(int i = 0; i <k-1; i++){
		vector<int> d;
		for(int j = i; j <=n-k; j += k-1){
			d.pb(b[j]);
		}
		ans = (ans + solve2(d)) % mod;
	}
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