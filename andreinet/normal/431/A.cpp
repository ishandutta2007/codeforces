#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);

    int a[5];
    for (int i = 1; i <= 4; i++)
        cin >> a[i];

    string S;
    cin >> S;

    int Sol = 0;
    for (int i = 0; i < int(S.length()); i++)
        Sol += a[S[i] - '0'];

    cout << Sol << "\n";
}