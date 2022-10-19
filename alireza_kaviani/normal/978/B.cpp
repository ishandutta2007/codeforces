#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , ans = 0;
    string s;
    cin >> n >> s;
    
    for(int i = 0 ; i < n - 2 ; i++)
    {
        if(s.substr(i , 3) == "xxx")
        {
            ans++;
        }
    }
    
    cout << ans << endl;
}