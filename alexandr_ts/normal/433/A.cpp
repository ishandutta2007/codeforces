#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    fr(i, n) {
        int t;
        cin >> t;
        if (t == 100)
            cnt1++;
        else
            cnt2++;
    }
    cnt2 %= 2;
    if (!cnt2 && cnt1 % 2 == 0) {
        cout << "YES";
        return 0;
    }
    if (cnt1 && cnt1 % 2 == 0 && cnt1 >= 2) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}