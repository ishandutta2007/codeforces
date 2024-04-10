#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
string s;

int main()
{
   // freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    int n, i, a0 = 0, a1 = 0, a2 = 0;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++){
        if (s[i] == '1')
            a1++;
        if (s[i] == '0')
            a0++;
        if (s[i] == '?')
            a2++;
    }
    if (a0 + a2 > a1)
        printf("00\n");
    if (! (a0 > a1 + a2 || a1 > a2 + a0 + 1)){
        if (s[n - 1] == '?'){
            if (a1 + 1 <= a0 + a2)
                printf("01\n");
            if (a0 + 1 <= a1 + a2 - 1)
                printf("10\n");
        }
        else
            if (s[n - 1] == '0')
                printf("10\n");
            else
                printf("01\n");
    }

    if (a1 + a2 > a0 + 1)
        printf("11\n");


    return 0;
}