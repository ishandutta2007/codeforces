#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a[200001],b[200001];
    cin >> a >> b;
    long long dem[4]={0,0,0,0};
    for (int i=n-1; i>=0;i--)
    {
         if (a[i]=='0' && b[i]=='0') dem[0]++;
         if (a[i]=='0' && b[i]=='1') dem[1]++;
         if (a[i]=='1' && b[i]=='0') dem[2]++;
         if (a[i]=='1' && b[i]=='1') dem[3]++;
    }
    long long t; t=dem[0]*dem[2]+dem[1]*dem[2]+dem[0]*dem[3];
    cout << t;
}