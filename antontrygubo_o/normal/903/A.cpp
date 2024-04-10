#include <bits/stdc++.h>

using namespace std;

void CFK(int n)
{
    while ((n>=7)&&(n%3!=0)) n-=7;
    if (n%3!=0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main ()
{
int n;
cin>>n;
int a;
for (int i = 0; i<n; i++)
{
    cin>>a; CFK(a);
}

}