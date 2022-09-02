#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
int n;
cin>>n;
double a[n];
double summa = 0;
for (int i = 0; i<n; i++) {cin>>a[i]; summa+=a[i];}
double need = 4.5*n;
sort(a, a+n);
int counter = 0;
while (summa<need)
{
    summa+=(5.0-a[counter]);
    counter++;
}
cout<<counter;

}