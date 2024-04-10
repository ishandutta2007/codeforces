#include <bits/stdc++.h>

using namespace std;

int read()
{
    string s;
    cin >> s;
    
    if (s == "monday") return 0;
    if (s == "tuesday") return 1;
    if (s == "wednesday") return 2;
    if (s == "thursday") return 3;
    if (s == "friday") return 4;
    if (s == "saturday") return 5;
    if (s == "sunday") return 6;
    assert(!"imp");
}

int main()
{
    int a = read(), b = read();
    
    for (int i = 28; i <= 31; i++)
    {
        if (i == 29) continue;
        
        if ((a + i) % 7 == b)
        {
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");
    return 0;
}