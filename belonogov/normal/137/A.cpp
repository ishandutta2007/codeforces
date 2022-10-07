#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
string s;
int n, i, kol, ans;
int main()
{
    //freopen("in", "r", stdin);
   // freopen("out", "w", stdout);
    cin >> s;
    n = s.length();
    kol = 1;
    ans = 0;
    for (i = 1; i < n; i++){
        if (s[i] == s[i - 1]){
            if (kol < 5)
                kol++;
            else{
                kol = 1;
                ans++;
            }
        }
        else{
            kol = 1;
            ans++;
        }
    }
    if (kol != 0)
        ans++;

    cout << ans;
     return 0;
}