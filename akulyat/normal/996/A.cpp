#include <bits/stdc++.h>

using namespace std;

long long n,i;
vector <long long> m;
int main()
{
cin>>n;
m.push_back(100);
m.push_back(20);
m.push_back(10);
m.push_back(5);
m.push_back(1);

long long ans=0;
for (i=0; i<5; i++)
    {
    long long z=n/m[i];
    n%=m[i];
    ans+=z;
    }

cout<<ans;

    return 0;
}