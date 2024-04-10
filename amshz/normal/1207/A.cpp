# include <bits/stdc++.h>

using namespace std;

int main(){
	long long b, p, f, h, c, t, ans;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> b >> p >> f >> h >> c;
		ans = 0;
		b -= b%2;
		//if (b == 1) ans = 0;
		if (h > c){
			if (b >= p*2) ans += h*p, b -= p*2;
			else ans += h*b/2, b = 0;
			b /= 2;
			ans += c*(min(b,f));
		}
		else{
			if (b >= f*2) ans += c*f, b -= f*2;
			else ans += c*b/2, b = 0;
			b /= 2;
			ans += h*(min(b,p));
		}
		cout << ans << endl;
	}
}