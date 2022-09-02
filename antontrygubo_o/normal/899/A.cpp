#include<iostream>

using namespace std;

int main()
{
int n;
cin>>n;
int a1 = 0;
int a2 = 0;

int b[n];
for (int i = 0; i<n; i++) cin>>b[i];
for (int i = 0; i<n; i++) if(b[i]==1) a1++; else a2++;
if (a2>=a1) cout<<a1;
else cout<<a2 + (a1-a2)/3;

}