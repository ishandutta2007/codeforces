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
    string s1, s2;
    int n1, n2, i, d;

    getline(cin, s1);
    getline(cin, s2);
    n1 = s1.length();
    n2 = s2.length();
    for (i = 0; i < n1; i++)
        if (s1[i] != ' ')
            a[s1[i]]++;
    for (i = 0; i < n2; i++)
        if (s2[i] != ' ')
            b[s2[i]]++;
    d = max('Z', 'z') + 2;
    for (i = 0; i < d; i++)
        if (b[i] > a[i])
        {
            cout << "NO";
            return 0;
        }

    cout << "YES";
    return 0;
}