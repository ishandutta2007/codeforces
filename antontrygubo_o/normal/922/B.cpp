#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
int coun = 0;
for (int i = 1; i<=n; i++)
for (int j = i; j<=n; j++)
{
    int k = i^j; 
    if ((k>=j)&&(k<i+j)&&(k<=n)) coun++; 
}
cout<<coun;
}