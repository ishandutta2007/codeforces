#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

int N;
int p[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> p[i];

    int t; cin >> t;
    while (t --) {
        int x;
        cin >> x;
        p[x] *= (-1);
    }

    stack <int> stk;
    for (int i = N; i; -- i) {
        if (p[i] < 0)
            stk.push(i);
        else {
            if (!stk.empty() && abs(p[stk.top()]) == p[i])
                stk.pop();
            else
                stk.push(i), p[i] *= (-1);
        }
    }

    if (!stk.empty())
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i <= N; ++ i)
            cout << p[i] << " \n"[i == N];
    }
    return 0;
}