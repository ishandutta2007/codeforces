#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<bitset>
using namespace std;
const unsigned long long INF = 1e17;
const int Y = 100100;
const long long A = 179, m = 1000000007, m2 = 1000000009;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
int arr[2 * Y];
bool dg[2 * Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> n >> k;
        queue<int>q;
        int mx = -1, ll = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            dg[i] = false;
        }
        for (int i = 2; i < n; ++i)if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])dg[i] = true;
        int r = k;
        for (int i = 1; i < r; ++i)if (dg[i])q.push(i);
        for (int l = 1; r <= n; ++l, ++r) {
            if (!q.empty() && q.front() == l)q.pop();
            int tmp = q.size();
            if (tmp > mx) {
                mx = tmp;
                ll = l;
            }
            if (dg[r])q.push(r);
        }
        cout << mx + 1 << " " << ll << "\n";
    }
    return 0;
}