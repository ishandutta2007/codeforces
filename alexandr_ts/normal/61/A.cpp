#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string s1;
    string s2;
    string ans;
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < s1.size(); i++)
        ans += ((s1[i] - '0') xor (s2[i] - '0')) + '0';
    cout << ans;
    return 0;

}