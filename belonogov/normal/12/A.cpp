#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int  a[10][10];

int main()
{
   string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    if (s1[0] == s3[2] && s1[1] == s3[1] && s1[2] == s3[0] &&
        s2[0] == s2[2])
            cout << "YES";
        else
            cout << "NO";

    return 0;
}