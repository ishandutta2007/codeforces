#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;
int a[MxN + 9];
int b[MxN + 9];

bool cmp1(const int i, const int j) {
    return a[i] + b[i] > a[j] + b[j];
}

bool cmp2(const int i, const int j) {
    return a[i] + b[i] < a[j] + b[j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] < b[i])
            v1.push_back(i);
        else
            v2.push_back(i);
    }


    if (v1.size() > v2.size()) {
        sort(v1.begin(), v1.end(), cmp1);
        cout << v1.size() << endl;
        for (int x : v1)
            cout << x << ' ';
    } else {
        sort(v2.begin(), v2.end(), cmp2);
        cout << v2.size() << endl;
        for (int x : v2)
            cout << x << ' ';

    }
    return 0;
}