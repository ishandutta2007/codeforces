#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        printf("%s\n", s.c_str());
    }
    return 0;
}