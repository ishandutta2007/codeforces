#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a[1000];

int main()
{
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    s1 += s2;
    cin >> s3;
    for(int i = 0; i < s1.size(); i++)
        a[s1[i]]++;
    for(int i = 0; i < s3.size(); i++)
        a[s3[i]]--;
    for(int i = 0; i < 1000; i++)
        if(a[i] != 0)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
}