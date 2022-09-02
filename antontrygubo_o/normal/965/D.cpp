#include<bits/stdc++.h>
using namespace std;


int main()
{
long long l, w;
cin>>w>>l;
int a[w-1];
for (int i = 0; i<w-1; i++) cin>>a[i];
long long minn;
long long temp = 0;
for (int i = 0; i<l; i++) temp+=a[i];
minn = temp;
for (int i = l; i<w-1; i++) {temp+=a[i]; temp-=a[i-l]; minn = min(minn, temp);}
cout<<minn;
}