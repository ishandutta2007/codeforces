#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    int N;
    cin >> N;
    cin >> str;

    int ans = 0;

    for (int i = 0; i < N; ++ i)
        if (str[i] == '<')
            ++ ans;
        else
            break;
    for (int i = N - 1; i >= 0; -- i)
        if (str[i] == '>')
            ++ ans;
        else
            break;

    cout << ans << '\n';
    return 0;
}