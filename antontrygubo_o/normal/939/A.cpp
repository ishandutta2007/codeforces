#include <bits/stdc++.h>
using namespace std;


int main() 
{
bool is = false;
int n;
cin>>n;
int a[n];
for (int i =0; i<n; i++){cin>>a[i]; a[i]--;}
for (int i = 0; i<n; i++) if (a[a[a[i]]]==i) is = true;
if (is) cout<<"YES";
else cout<<"NO";

}