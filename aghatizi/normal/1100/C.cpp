#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

#define X real()
#define Y imag()

const int maxn = 1e5 + 20;
const ld pi = acos(-1);

int t[maxn];

bool check(ld R , int n , ld r)
{
	complex<ld> pt1 , pt2;
	pt1 = polar(r + R , (ld)0);
	pt2 = polar(r + R , (2 * pi) / n);

	return (pt1.X - pt2.X) * (pt1.X - pt2.X) + (pt1.Y - pt2.Y) * (pt1.Y - pt2.Y) >= 4 * R * R;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , r;
	cin >> n >> r;

	ld L = 0 , R = 1e9;
	for(int i = 0; i < 200; i++)
	{
		ld m = (L + R) / 2;

		if(!check(m , n , r))
			R = m;
		else
			L = m;
	}

	cout << fixed << setprecision(20) << R << endl;
}

// (x , 0)