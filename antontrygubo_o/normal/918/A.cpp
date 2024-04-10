#include<bits/stdc++.h>
using namespace std;
int a[50];

bool inarray(int k)
{
    for (int i = 0; i<50; i++) if (k==a[i]) return true;
    return false;
}

int main()
{
int n;
cin>>n;

a[0] = 1; a[1] = 2;
for (int i = 2; i<50; i++) a[i] = a[i-1] + a[i-2];

for (int i = 1; i<=n; i++) if (inarray(i))cout<<"O";
else cout<<"o";


}