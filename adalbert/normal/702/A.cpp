#include <bits/stdc++.h>
using namespace std;
map <string ,long long > use;
string st,st2;
vector <long long > vec;
long long n,a[1000000],mx,k;

int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    for (int i=1;i<=n;i++)
        if (a[i]>a[i-1]) k++; else
    {
        mx=max(k,mx);
        k=1;
    }
    mx=max(k,mx);
    cout<<mx;

}