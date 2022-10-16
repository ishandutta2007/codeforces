#include <iostream>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int v[NMAX];

int stk[NMAX];
int sz;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    for (int i = 1; i <= N; ++ i) {
        int st = 1;
        int dr = sz;
        int ans = 0;

        while (st <= dr) {
            int mid = (st + dr) >> 1;
            if (stk[mid] <= v[i]) {
                ans = mid;
                st = mid + 1;
            }
            else
                dr = mid - 1;
        }

        stk[ans + 1] = v[i];
        if (ans == sz)
            ++ sz;
    }

    cout << sz << '\n';
    return 0;
}