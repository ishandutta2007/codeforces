#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    cin >> N >> M;

    N = N > M ? M: N;

    if (N & 1) cout << "Akshat\n";
    else cout << "Malvika\n";
}