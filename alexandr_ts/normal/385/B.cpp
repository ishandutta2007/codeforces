#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1000000];
int b[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    if(s.size() <= 3)
    {
        cout << 0;
        return 0;
    }
    int cur = 0;
    for(int i = 0; i < s.size() - 3; i++)
        if(s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
        {
            a[cur] = i;
            b[cur] = i + 3;
            cur++;
        }
    a[cur] = s.size();
    b[cur] = s.size();

    int ans = 0;
    for(int i = 0; i < cur; i++)
    {
        ans += (a[i] + 1) * (b[i + 1] - b[i]);
    }
    cout << ans;
    return 0;
}