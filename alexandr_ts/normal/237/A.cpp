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
    int h, m;
    int qua = 1;
    int mm = 0;
    int lasth, lastm;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        mm = max(mm, qua);
        cin >> h >> m;
        if(h == lasth && m == lastm)
            qua++;
        else
        {
            qua = 1;
            lasth = h;
            lastm = m;
        }
        mm = max(mm, qua);
    }
    cout << mm;
}