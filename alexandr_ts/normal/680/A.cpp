#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N];

string str(int n) {
    string ans;
    while (n > 0) {
        ans = (char)(n % 10 + '0') + ans;
        n /= 10;
    }
    return ans;
}

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    fr(i, 5)
        cin >> a[i];
    sort(a, a + 5);
    int sum = accumulate(a, a + 5, 0);
    int ans = sum;
    fr(i, 4)
        if (a[i] == a[i + 1])
            ans = min(ans, sum - a[i] - a[i + 1]);
    fr(i, 3)
        if (a[i] == a[ i + 1] && a[i] == a[i + 2])
            ans = min(ans, sum - a[i] - a[i + 1] - a[i + 2]);
    cout << ans;

}