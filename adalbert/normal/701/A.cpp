#include <bits/stdc++.h>
#include <map>
using namespace std;
long long n,b[200],m,x,y,z,w,ans;
string st,s1,s2;
pair <long long , long long> a[10000];
char c;
int main()
{
    cin>>n;
     for (int i=1;i<=n;i++)
     {
         cin>>a[i].first;
         a[i].second=i;
     }
     sort(a+1,a+1+n);
     for (int i=1;i<=n/2;i++)
        cout<<a[i].second<<' '<<a[n-i+1].second<<'\n';
}