#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{

string s1, s2;
cin>>s1>>s2;
int n = s1.length();
int a[n] = {};
for (int i = 0; i<n; i++) 
{
    if (s1[i]=='0') a[i]++;
    if (s2[i]=='0') a[i]++;
}

int counter = 0;
for (int i = n-1; i>=1; i--)
{
    if (a[i]+a[i-1]>=3)
    {
        counter++;
        if (a[i]+a[i-1]==4) {a[i] = 0; a[i-1]= 1;}
        else {a[i]=0; a[i-1]=0;}
    }
}
cout<<counter;

}