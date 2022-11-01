#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s1;
    cin >> s1;
    for(int i = 0; i < k; i++)
    {
        int j = 0;
        while(j < s1.size())
        {
            if(s1[j] == 'B' && s1[j + 1] == 'G')
            {
                swap(s1[j], s1[j + 1]);
                j++;
            }
            j++;
        }
    }
    cout << s1;
    return 0;
}