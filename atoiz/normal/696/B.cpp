#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ios>
#include <iomanip>

using namespace std;

int N, desc[100009]; // desc include
double arr[100009];
vector<int> children[100009];

int dfsDesc(int u)
{
    int cnt = 1;
    for (int i = 0; i < children[u].size(); ++i) {
		int v = children[u][i];
		cnt += dfsDesc(v);
    }
    desc[u] = cnt;
//    cerr << u << ": " << cnt << endl;
    return cnt;
}

void dfsVal(int u)
{
    double curArr = arr[u] + 1;
    double descSum = 0;
    for (int i = 0; i < children[u].size(); ++i) {
		int v = children[u][i];
//		cerr << v << endl;
        descSum += desc[v];
    }

    for (int i = 0; i < children[u].size(); ++i) {
		int v = children[u][i];
        arr[v] = curArr + (descSum - desc[v]) / 2;
//        cerr << v << ": " << arr[v] << endl;
        dfsVal(v);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 100009; ++i) {
		children[i].clear();
		desc[i] = 0;
		arr[i] = 0;
    }

    cin >> N;
    for (int i = 2; i <= N; ++i) {
		int j;
		cin >> j;
        children[j].push_back(i);
    }

    dfsDesc(1);

	arr[1] = 1;
	dfsVal(1);

	for (int i = 1; i <= N; ++i) {
		cout << fixed << setprecision(15) << arr[i] << " ";
	}
	cout << endl;
}