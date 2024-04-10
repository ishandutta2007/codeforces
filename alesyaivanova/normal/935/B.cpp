#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'U')
            bal++;
        else
            bal--;
        if (bal == 0 && s[i] == s[i + 1])
            ans++;
    }
    cout << ans;
}