#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e2 + 1;

char a[N][N];

int main() {
    int n, t;
    cin >> n >> t;
    if (t == 0) {
        cout << "YES" << endl;
        fr(i, n) {
            fr(j, n)
                cout << 'S';
            cout << endl;
        }
        return 0;
    }
    int cnt = (n * n + 1) / 2;
    if (t > cnt) {
        cout << "NO";
        return 0;
    }
    cnt = 0;
    cout << "YES" << endl;
    fr(i, n)
        fr(j, n)
            if ((i + j) % 2 == 0 && cnt < t)
                a[i][j] = 'L', cnt++;
    fr(i, n) {
        fr(j, n)
            if (a[i][j] == 'L')
                cout << a[i][j];
            else
                cout << 'S';
        cout << endl;
    }

}