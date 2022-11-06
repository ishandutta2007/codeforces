#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

typedef pair<ld , ld> point;

const int maxn = 1e5 + 20;

point A[10] , B[10];

ld get(point a , point b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ld a , b , c;
	cin >> a >> b >> c;

	ld x1 , y1 , x2 , y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ld res = abs(x1 - x2) + abs(y1 - y2);

	A[1].first = x1 , A[1].second = (-a * x1 - c) / b;
	A[2].first = (-b * y1 - c) / a , A[2].second = y1;

	B[1].first = x2 , B[1].second = (-a * x2 - c) / b;
	B[2].first = (-b * y2 - c) / a , B[2].second = y2;

	point X = make_pair(x1 , y1) , Y = make_pair(x2 , y2);

	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			res = min(res , get(X , A[i]) + get(A[i] , B[j]) + get(B[j] , Y));

	cout << fixed << setprecision(10) << res << endl;
}