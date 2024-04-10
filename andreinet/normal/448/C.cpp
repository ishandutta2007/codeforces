#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 5005, INF = 0x3f3f3f3f;

int A[Nmax];
int N;

bool Check()
{
    for (int i = 1; i <= N; i++)
        if (A[i] > 0)
            return true;

    return false;
}

long long Solve(const int left, const int right)
{
    if (left > right) return 0;
    if (left == right) return 1;

    int mins = INF;

    for (int i = left; i <= right; i++)
        mins = min(mins, A[i]);

    long long cost = 0;
    for (int i = left; i <= right; i++)
        A[i] -= mins;

    for (int i = left; i <= right;)
    {
        for (; !A[i] && i <= right; i++);
        int l = i;
        for (; A[i] && i <= right; i++);
        int r = i - 1;

        cost += Solve(l, r);
    }

    return min(cost + mins, 1LL * (right - left + 1));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    long long Ans = Solve(1, N);

    cout << Ans << "\n";
}