#include <bits/stdc++.h>

using namespace std;

int main() {
int n;
cin>>n;
int a[n];
long long summ = 0;
for (int i = 0; i<n; i++) {cin>>a[i]; summ+=a[i];}
summ=(summ+1)/2;
int i=-1;
long long summa =0;
while (summa<summ)
{
    i++;
    summa+=a[i];
}
cout<<i+1;
}