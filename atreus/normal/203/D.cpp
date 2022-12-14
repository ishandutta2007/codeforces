#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	double a, b, m;
	cin >> a >> b >> m;
	double vx, vy, vz;
	cin >> vx >> vy >> vz;
	double x = a/2, y = m, z = 0;
	double t = abs(y / vy);
	ld X = a/2. + t * vx, Z = t * vz;
	while (X > 2.*a)
		X -= 2.*a;
	while (X < 0)
		X += 2.*a;
	if (X > a){
		X -= a;
		X = a - X;
	}
	while (Z > 2.*b)
		Z -= 2.*b;
	while (Z < 0)
		Z += 2.*b;
	if (Z > b){
		Z -= b;
		Z = b - Z;
	}
	cout << fixed << setprecision(6) << X << " " << Z << endl;
}