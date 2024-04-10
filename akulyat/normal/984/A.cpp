#include <bits/stdc++.h>

using namespace std;

long n,i;
vector <long> m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
{
long a; cin>>a; m.push_back(a);
}
sort(m.begin(), m.end());
cout<<m[(n-1)/2];
    return 0;
}