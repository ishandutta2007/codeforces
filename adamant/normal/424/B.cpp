#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define FILEIN "test.in"
#define FILEOUT "test.out"

int n, k, s;

struct Point {
    double dist;
    int population;

    bool operator<(const Point &other) const {
        return dist < other.dist;
    }
};

Point V[1005];

double distance(int x, int y) {
    double d = sqrt((double)(x * x + y * y));

    return d;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

    scanf("%d %d", &n, &s);

    for ( int i = 1, x, y, k; i <= n; i++ ) {
        scanf("%d %d %d", &x, &y, &k);
        V[i].dist = distance(x, y);
        V[i].population = k;
    }

    sort(V+1, V+n+1);

    int i;
    for ( i = 1; i <= n && s < 1000000; i++ ) {
        s += V[i].population;
    }

    if (s < 1000000)
        printf("-1\n");
    else {
        printf("%.7lf", V[i-1].dist);
    }

	return 0;
}