#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int n, t;

bool rev = false;

int que(int l, int r){
	assert(0 <= l && l <= r && r < n);
	if(rev){
		l = n-1-l;
		r = n-1-r;
		swap(l,r);
	}
	cout << "? " << l+1 << ' ' << r+1 << endl;
	int t;
	cin >> t;
	if(t == -1) exit(0);
	return t;
}

void yay(string s){
	cout << "! " << s << endl;
	exit(0);
}

void solve1(){
	string ans(n, '?');
	rep(i,0,n){
		int cur = t;
		while(cur == t){
			que(i,i);
			cur = que(i,i);
		}
		ans[i] = cur+t>n ? '1' : '0';
		while(cur != t){
			que(i,i);
			cur = que(i,i);
		}
	}
	yay(ans);
}

void cnts(vi &c){
	int tol = 0;
	rep(i,0,n/2){
		int mvs = 0;
		int res = -1;
		do {
			++mvs;
			res = que(2*i,2*i+1);
		} while((mvs+res+t)%2==0);
		if(mvs%2){
			c[i] = (t+2*i-2*tol-res + 2)/2;	
		} else {
			c[i] = (2+(res+t-n))/2;
		}
		tol += c[i];
		while(mvs%2 || (mvs+res+t)%2){
			++mvs;
			res = que(2*i,2*i+1);
		}
	}
}

void solve2(){
	string ans(n, '?');
	
	vi c1(n/2), c2(n/2);
	cnts(c1);
	rev = true;
	cnts(c2);
	reverse(all(c2));
	int tor = 0;
	trav(x, c2) tor += x;
	int tol = 0;
	rep(i,0,n){
		if(i%2){
			ans[i] = '0' + c1[i/2] - (ans[i-1]-'0');
			tor -= c2[i/2];
		} else {
			ans[i] = '0' + (t-tor-tol);	
		}
		tol += ans[i]-'0';
	}
	yay(ans);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	if(t==0) yay(string(n,'0'));
	if(t==n) yay(string(n,'1'));

	if(abs(n - 2*t) != 1)
		solve1();
	else
		solve2();
}