#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, m;
cin>>n>>m;
long long a[n];
long long b[m];
for (int i = 0; i<n; i++) cin>>a[i];
for (int i = 0; i<m; i++) cin>>b[i];
long long product[n][m];
for (int i = 0; i<n; i++)
for (int j = 0; j<m; j++)
product[i][j] = a[i]*b[j];
long long maxx[n];
for (int i = 0; i<n; i++)
{
    maxx[i] =product[i][0];
    for (int j = 1; j<m; j++) maxx[i] = max(maxx[i], product[i][j]);
}

sort(maxx, maxx+n);
cout<<maxx[n-2];

}