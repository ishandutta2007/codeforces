#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//vector <int> a;
int a[100000];
int b[100000];

int main()
{
     int i, j, n, sum = 0;
    string s;
    cin >> s;
    n = s.length();
    i = n - 1;
    while (s[i] == '0')
    {
        i--;
    }
    if (i == 0)
    {
        cout << n - 1;
        return 0;
    }
    for (j = 0; j < i; j++)
        if (s[j] == '0')
            sum++;
    sum += n + 1;
    cout << sum;

    return 0;
}