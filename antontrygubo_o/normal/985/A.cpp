#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin>>n;
    int a[n/2];

    ll summa1 = 0;
    ll summa2 = 0;
    for (int i = 0; i<n/2; i++) {cin>>a[i]; a[i]--;}
    sort(a, a+n/2);
    for (int i = 0; i<n/2; i++)
    {
        summa1+=abs(a[i]-2*i);
        summa2+=abs(a[i]-2*i-1);
    }
    cout<<min(summa1, summa2);

}