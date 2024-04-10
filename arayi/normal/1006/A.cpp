// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{  
    vector <int> a;
    int n;
    cin>>n;
    int b;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]%2==1)
        {
            a[i]++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        cout<<--a[j]<<" ";
    }
}