#include <bits/stdc++.h>
using namespace std;
 
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >
 
const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;
 
 
int a1, b1, r1, a2, b2, r2;
 
long double get(long double a, long double b){
	return sqrt(a * a + b * b);
}
long double get2(long double r1, long double r2, long double d){
	long double a = r2 * r2 + d * d - r1*r1;
	a/=2*r2*d;
	a = acos(a);
	return a*r2*r2 - r2*r2*sin(a) * cos(a);
}
 
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a1 >> b1 >> r1;
    cin >> a2 >> b2 >> r2;
 
    if(r1 < r2) {
        swap(r1, r2);
        swap(a1, a2);
        swap(b1, b2);
    }
    long double dis = get(a2 - a1, b2 - b1);
    if(r2 + r1 < dis + 0.5e-18L){
    	cout << 0.0 << endl;
    	return 0;
    }
    if(dis + r2 < r1 + 1e-8){
    	long double cur = acosl(-1.0) * r2 * r2;
    //	cout << (double)cur << endl;
    	printf("%.12f\n", (double)cur);
    	return 0;
    }
    printf("%.12lf\n", double(get2(r1, r2, dis) + get2(r2, r1, dis)));
    return 0;
}