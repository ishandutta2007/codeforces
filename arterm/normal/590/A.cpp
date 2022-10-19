#include <bits/stdc++.h>


using namespace std;

const int M = 500500;

int n, a[M];
bool u[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void kill() {
    u[0] = u[n - 1] = true;

    for (int i = 1; i < (n - 1); ++i)
        if (a[i - 1] == a[i] || a[i + 1] == a[i])
            u[i] = true;
        else
            u[i] = false;
}

void finish() {
    int ans = 0;

    for (int i = 1; i < (n - 1); ) {
        if (u[i]) {
            ++i;
            continue;
        }

        int j = i;
        while (j < n && !u[j])
            ++j;
            
        int len = j - i;
        ans = max(ans, (len + 1) / 2);

        int x = i, y = j - 1;
        while (x <= y) {
            a[x] = a[x - 1];
            a[y] = a[y + 1];
            --y;
            ++x;
        }


        i = j;
    }

    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    finish();
    return 0;
}