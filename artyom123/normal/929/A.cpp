#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
        if ( i >= 1 && a[i] - a[i - 1] > k) {
            cout << -1;
            return 0;
        }

    }

    int now = a[1] - a[0];
    int answer = 1;
    for ( int i = 1; i < n; i++) {
        if ( i == n - 1) {
            break;
        }
        if ( now + a[i + 1] - a[i] > k) {

            answer += 1;
            now = a[i + 1] - a[i];
        }
        else {
            now += a[i + 1] - a[i];
        }
    }
    cout << answer;





    return 0;
}