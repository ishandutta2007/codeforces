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
int arr[Y];
int R[Y];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool res = true;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            R[arr[i]] = i;
        }
        int w = 1;
        while (true) {
            int id = R[w];
            for (int i = id; i <= n; ++i) {
                if (arr[i] == w) {
                    ++w;
                }
                else {
                    res = false;
                }
            }
            n = id - 1;
            if (n == 0 || res == false)break;
        }
        if (res)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}