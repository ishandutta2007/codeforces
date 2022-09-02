#include<bits/stdc++.h>
using namespace std;

int main()
{
int m, n;
cin>>n>>m;
char a[4][n];
for (int i = 0; i<4; i++)
for (int j = 0; j<n; j++) a[i][j]='.';
if (m%2==0)
{
    for (int i = 1; i<1+m/2; i++) {a[1][i] = '#'; a[2][i] = '#';}
}

if (m%2==1)
{
    a[1][n/2] = '#';
    if (m<=n-2)
    {
        for (int i = 1; i<1+m/2; i++) {a[1][i] = '#'; a[1][n-1-i] = '#';}
    }
    else
    {
        m-=(n-2);
        for (int i = 1; i<n-1; i++) {a[1][i] = '#';}
        for (int i = 1; i<1+m/2; i++) {a[2][i] = '#'; a[2][n-1-i] = '#';}
    }
}
cout<<"YES"<<endl;
for (int i = 0; i<4; i++)
{
    for (int j = 0; j<n; j++) cout<<a[i][j];
    cout<<endl;
}

}