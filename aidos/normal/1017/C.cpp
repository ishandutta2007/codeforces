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

int b[100100];
vector<int> get1(int n){
	vector<int>res;
	int mid = (n+1)/2;
	int l = mid, r = mid;
	int st = 1, en = n;
    int cur = 0;
    while (l > 0 || r <= n) {
        
        if (l == r) {
            b[l] = st++;
        } else {
            if (r <= n) {
                if (cur & 1) {
                    b[r] = en--;
                } else {
                    b[r] = st++;
                }
            }
            if (l > 0) {
                if (cur & 1) {
                    b[l] = en--;
                } else {
                    b[l] =st++;
                }
            } 
            
        }
        cur ++;
        l --, r ++;
    }
    for(int i = 1; i <= n; i++){
    	res.pb(b[i]);
    }
    return res;
}

vector<int> get2(int n){
	vector<int>res;
	int mid = (n+1)/2;
	int l = mid, r = mid;
	int st = 1, en = n;
    int cur = 0;
    while (l > 0 || r <= n) {
        
        if (l == r) {
            b[l] = en--;
        } else {
            if (r <= n) {
                if (cur & 1) {
                    b[r] = en--;
                } else {
                    b[r] = st++;
                }
            }
            if (l > 0) {
                if (cur & 1) {
                    b[l] = en--;
                } else {
                    b[l] =st++;
                }
            } 
            
        }
        cur ++;
        l --, r ++;
    }
    for(int i = 1; i <= n; i++){
    	res.pb(b[i]);
    }
    return res;
}

int n;
int t[100100];
int get(int x){
	int res = 0;
	while(x>=0){
		res = max(res, t[x]);
		x = (x&(x+1)) - 1;
	}
	return res;
}
void upd(int p, int val){
	while(p <= n){
		t[p] = max(t[p], val);
		p |= p + 1;
	}
}
int calc1(vector<int> a){
	for(int i = 0; i<= n; i++) t[i] = 0;

	for(int i = 0;i < a.size(); i++){
		int g = get(a[i]);
		upd(a[i], g+1);
	}
	return get(n);
}
int calc2(vector<int> a){
		for(int i = 0; i<= n; i++) t[i] = 0;

	for(int i = 0;i < a.size(); i++){
		int g = get(n-a[i]);
		upd(n-a[i], g+1);
	}
	return get(n);
}

vector<int> get3(int n){
	vector<int>res;
	int k = 1;
	while(k * k < n) k++;
	for(int i = n; i > 0; i-=k){
		int g = max(i-k+1, 1);
		for(int j = g; j <= i; j++){
			res.pb(j);
		}
	}
    return res;
}


void solve(){
	cin >> n;
	vector<int> a = get1(n);
	vector<int> b = get2(n);
	int cura = calc1(a) + calc2(a);
	
	int curb = calc1(b) + calc2(b);
	if(cura>curb) {
		a = b;
		cura = curb;
	}
	b = get3(n);
	curb =calc1(b) + calc2(b); 
	if(cura>curb) {
		a = b;
		cura = curb;
	}
	for(int i = 0; i < a.size(); i++){
		printf("%d ", a[i]);
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