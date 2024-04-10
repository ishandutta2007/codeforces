#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    while ((a!=0)&&(b!=0))
    {
        if (a<b) swap(a, b);
        else a = a%b;
    }
    return a+b;
}

int main()
{
ios_base::sync_with_stdio(0);
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];

int number = 0;
for (int i =0; i<n; i++) if(a[i]==1) number++;
if (number) {cout<<n-number; return 0;}

int gcd_all = a[0];
for (int i = 0; i<n; i++) gcd_all = gcd(gcd_all, a[i]);
if (gcd_all != 1) {cout<<-1; return 0;}

int minimum = n;
for (int i = 0; i<n; i++)
{
    int gcd_i = a[i];
    int idx = i;
    while ((gcd_i!=1)&&(idx-i<minimum)&&(idx<n-1))
    {
        idx++;
        gcd_i = gcd(gcd_i, a[idx]);
    }
    if (gcd_i==1) minimum = idx-i;

}
cout<<minimum+n-1;

}