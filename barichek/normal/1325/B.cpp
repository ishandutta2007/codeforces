#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 
    int t, n;
 
    cin >> t;
    while(t--)
    {
        int a[100000+10];
        int b[100000+10];
        int sum = 1;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        //int sz = sizeof(a)/sizeof(a[0]);
        sort(a, a + n);
        for(int j = 1; j < n; j++)
        {
            if(a[j] != a[j - 1])
                sum++;
        }
        cout << sum << endl;
    }
}