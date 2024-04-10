#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, a, b;
cin>>n>>a>>b;
int a1 = 0;
while ((a1<=n)&&((n-a1)%b!=0)) a1+=a;
if (a1>n) {cout<<-1; return 0;}
int k = a1/a;
int l = (n-a1)/b;
for (int i = 0; i<k; i++)
{
    cout<<a*i+a<<' ';
    for (int j = 1; j<a; j++) cout<<a*i+j<<' ';
}

for (int i = 0; i<l; i++)
{
    cout<<a1+b*i+b<<' ';
    for (int j = 1; j<b; j++) cout<<a1+b*i+j<<' ';
}

}