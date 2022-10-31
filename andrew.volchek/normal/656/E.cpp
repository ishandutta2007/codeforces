#include <bits/stdc++.h>


using namespace std;
const int maxn = 15;
int d[maxn][maxn];

int n;


bool h(int i, int j, int k);
bool g(int i, int j);

bool f(int i) {
    g(i, 0);
    return i == n - 1 ? false : f(i + 1);
}

bool g(int i, int j) {
    h(i, j, 0);
    return j == n - 1 ? false : g(i, j + 1);
}

bool h(int i, int j, int k) {
    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    return k == n - 1 ? false : h(i, j, k + 1);
}

bool u(int i);
bool v(int i, int j);

int ans;

bool u(int i) {
    v(i, 0);
    return i == n - 1 ? false : u(i + 1);
}

bool v(int i, int j) {
    ans = max(ans, d[i][j]);
    return j == n - 1 ? false : v(i, j + 1);
}



bool y(int i, int j);

bool x(int i) {
    y(i, 0);
    return i == n - 1 ? false : x(i + 1);
}

bool y(int i, int j) {
    cin >> d[i][j];
    return j == n - 1 ? false : y(i, j + 1);
}

int main() {

    srand(time(NULL));




    cin >> n;
    x(0);


    f(0);
    u(0);


    cout << ans << endl;





    return 0;
}