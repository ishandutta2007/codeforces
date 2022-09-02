#include <bits/stdc++.h>

using namespace std;

int main ()
{
int n;
cin>>n;
int box[n];
for (int i = 0; i<n; i++) cin>>box[i];
sort(box, box+n);
int maxx = 0;
int i = 0;
int current = 1;
while (i!=n)
{
    while ((box[i+1]==box[i])&&(i<n))
    {
        current++;
        i++;
    }
    maxx = max(maxx, current);
    current = 1;
    i++;
}
cout<<maxx;
}