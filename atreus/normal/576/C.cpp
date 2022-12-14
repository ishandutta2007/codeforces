#include <bits/stdc++.h>

#define MP make_pair
#define F first
#define PB push_back
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int SQRT = 1000;

struct Point{
	int x;
	int y;
	int idx;
	bool operator < (const Point &other) const{
		if (x / SQRT != other.x / SQRT)
			return x < other.x;
		if ((x / SQRT) % 2 == 0)
			return y < other.y;
		return y > other.y;
	}
};

const int maxn = 1e6 + 10;

Point point[maxn];

int main (){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> point[i].x >> point[i].y;
		point[i].idx = i + 1;
	}
	sort(point, point + n);
	for (int i = 0; i < n; i++)
		cout << point[i].idx << " ";
}