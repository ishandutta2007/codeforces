#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

string s, s2;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> s;
    s2 = s;

    reverse(s2.begin(), s2.end());
    cout << s << s2;


    return 0;
}