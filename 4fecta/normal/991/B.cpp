#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)
vector<double> a;
double sum() {
    double ret = 0;
    for (double i : a) {
        ret += i;
    }
    return ret;
}

int main() {
    boost();

    double n, u;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u;
        a.push_back(u);
    }
    sort(a.begin(), a.end());
    int ptr = 0;
    while (sum() / n < 4.5) {
        a[ptr++] = 5;
    }
    printf("%d\n", ptr);

    return 0;
}