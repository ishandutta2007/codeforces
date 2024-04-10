# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;
const int xn = 6e1+10;
const int xk = 1e2+10;

int a, b, c, d, e, f, ans;

void kam1(){
	int mn = min(b, c);
	mn = min(mn, d);
	ans += mn*f;
	d -= mn;
}
void kam2(){
	int mn = min(a, d);
	ans += mn*e;
	d -= mn;
}


int main(){
	fast_io;
	
	cin >> a >> b >> c >> d >> e >> f;
	
	if (f > e){
		kam1(), kam2();
	}
	else{
		kam2(), kam1();
	}
	cout << ans << endl;
	
	return 0;
}