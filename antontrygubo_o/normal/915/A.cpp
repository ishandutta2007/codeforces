#include <bits/stdc++.h>

using namespace std;

int main() 
{
int n, k;
cin>>n>>k;
int litr;
int minn = 1000000000;
for (int i = 0; i<n; i++) {cin>>litr; if (k%litr==0) minn = min(minn, k/litr);}
cout<<minn;
}