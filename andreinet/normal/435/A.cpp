#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int s = M, sol = 0;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        if (x <= s)
            s -= x;
        else
        {
            s = M - x;
            sol++;
        }
    }
    if (s < M) sol++;

    cout << sol << "\n";

}