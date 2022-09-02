#include<bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
string s;
cin>>s;
bool can[n] = {0};
for (int i = 0; i<n-1; i++) 
{
    if (s[i]=='1') can[i] = true;
}    
can[n-1] = 1;
int maxx = -1;
int tempmax = -1;

bool kek = true;
for (int i = 0; i<n; i++)
{
    if (a[i]<maxx) kek = false;
    tempmax = max(tempmax, a[i]);
    if (can[i]==0) maxx = tempmax;
}

    if (kek) cout<<"YES";
    else cout<<"NO";
 
}