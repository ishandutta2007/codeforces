#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    int b[n];
    for (int i = 0; i<n; i++) b[i]=a[i];
    sort(b, b+n);
    for (int i = 0; i<n; i++)
    {
        int j = 0;
        while (a[i]!=b[j]) j++;
        a[i] = b[(j+1)%n];
    }
    for (int i = 0; i<n; i++) cout<<a[i]<<' ';
}