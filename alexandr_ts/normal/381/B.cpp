#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a[10000000];
int b[100000];
int c[100000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        b[a[i]]++;
        c[a[i]]++;
    }

    int qua = 0;
    int las;


for(int i = 0; i <= 10000; i++)
        if(c[i] > 0)
        {
            qua++;
            c[i]--;
            las = i;
        }

    for(int i = las - 1; i >= 0; i--)
        if(c[i] > 0)
        {
            c[i]--;
            qua++;
        }

    cout << qua << endl;
    for(int i = 0; i <= 10000; i++)
        if(b[i] > 0)
        {
            cout << i << " ";
            b[i]--;
            las = i;
        }

    for(int i = las - 1; i >= 0; i--)
        if(b[i] > 0)
        {
            cout << i << " ";
            b[i]--;

        }

    return 0;
}