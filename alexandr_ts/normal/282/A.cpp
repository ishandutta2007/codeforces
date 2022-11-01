#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    int n;
    string s;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s[1] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans;
    return 0;
}