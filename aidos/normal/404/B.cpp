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
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
double a, b, d;
void add(double &x, double &y, double t){
	//cout << x << " " << y << endl;
	if(t <= 1e-9) return;
	if(y == 0.0){
		if(x < a){
			double z = t - a + x;
			if(z >= 0.0){
				x = a;
				add(x, y, z);
			}
			else {
				x += t;
			}
		}	
		else {
			if(t > a) {
				y = a;
				add(x, y, t - a);
			}
			else 
				y += t;
		}
	}
	else if(x == a){
		if(y < a){
			double z = t - a + y;
			if(z >= 0.0){
				y = a;
				add(x, y, z);
			}
			else {
				y += t;
			}
		}
		else {
			if(t > a){
				x = 0.0;
				add(x, y, t - a);
			}
			else x -= t;
		}
	}
	else if(y == a){
		if(x > 0.0){
			double z = t - x;
			if(z >= 0.0){
				x = 0.0;
				add(x, y, z);
			}
			else {
				x -= t;
			}
		}
		else {
			if(t > a){
				y = 0.0;
				add(x, y, t - a);
			}
			else y-= t;
		} 
	}
	else {
		if(y > 0.0){         
			double z = t - y;
			if(z >= 0.0){
				y = 0.0;
				add(x, y, z);
			}
			else {
				y-=t;
			}
		}
		else {
			if(t > a){
				x = a;
				add(x, y, t - a);
			}
			else {
				x += t;
			}
		}
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> a >> d >> b;
    double x = 0.0, y  = 0.0, t = d/(4.0 * a);
    int r = (int) t;
    t = d - 4.0 * a * r;
    for(int i = 1; i <= b; i++){
    	add(x, y, t);
    	printf("%.6lf %.6lf\n", x, y);
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}