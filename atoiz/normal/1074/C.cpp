#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
const int MAX = 301000;
int X[MAX], Y[MAX], x_min, x_max, y_min, y_max;
vector<int> idxs;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i];
    x_min = *min_element(X, X+n);
    x_max = *max_element(X, X+n);
    y_min = *min_element(Y, Y+n);
    y_max = *max_element(Y, Y+n);

    for (int i = 0; i < n; ++i) {
        if (X[i] == x_min) idxs.push_back(i);
        else if (X[i] == x_max) idxs.push_back(i);
        else if (Y[i] == y_min) idxs.push_back(i);
        else if (Y[i] == y_max) idxs.push_back(i);
    }

	int peri = 0;
    for (int id1 = 0; id1 < (int)idxs.size(); ++id1) {
        for (int id2 = id1 + 1; id2 < (int)idxs.size(); ++id2) {
			int i1 = idxs[id1], i2 = idxs[id2];
            for (int i3 = 0; i3 < n; ++i3) {
                if (i3 == i1 || i3 == i2) continue;
                int tmp = max3(X[i1], X[i2], X[i3]) - min3(X[i1], X[i2], X[i3]);
                tmp += max3(Y[i1], Y[i2], Y[i3]) - min3(Y[i1], Y[i2], Y[i3]);
                peri = max(peri, tmp * 2);
            }
        }
    }

    cout << peri << ' ';
    for (int i = 4; i <= n; ++i) cout << 2 * (x_max + y_max - x_min - y_min) << ' ';
}