#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] == 'R' && s[i + 1] == 'U') || (s[i] == 'U' && s[i + 1] == 'R'))
        {
            ans++;
            i++;
        }
    }
    cout << n - ans;
}