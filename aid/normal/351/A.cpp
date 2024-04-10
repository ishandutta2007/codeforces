#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

bool cmp(double x, double y) {
    return x - floor(x) < y - floor(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> v;
    double sum = 0;
    int ans = 0, k = 0;
    for(int i = 0; i < 2 * n; i++) {
        double d;
        cin >> d;
        if(d - floor(d) <= EPS) {
            k++;
            continue;
        }
        v.push_back(d);
        sum += d;
        ans += ceil(d);
    }
    sort(v.begin(), v.end(), &cmp);
    n = v.size();
    int i = 0;
    for(; i < (n - k) / 2; i++)
        ans += floor(v[i]) - ceil(v[i]);
    int bans = ans;
    for(; i < min(n, (n + k) / 2); i++) {
        ans += floor(v[i]) - ceil(v[i]);
        if(fabs(bans - sum) > fabs(ans - sum))
            bans = ans;
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << fabs(bans - sum) << '\n';
}