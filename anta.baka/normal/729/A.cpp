#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector < bool > del(n, false);
    for(int i = 0; i < n; i++)
        if(i + 2 <= n-1 && s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o')
        {
            del[i] = 1; del[i+1] = 1; del[i+2] = 1; i += 2; cout << "***";
        }
        else if(i + 1 <= n-1 && i != 0 && del[i-1] && s[i] == 'g' && s[i+1] == 'o')
        {
            del[i] = 1; del[i+1] = 1; i++;
        }
        else
            cout << s[i];
}