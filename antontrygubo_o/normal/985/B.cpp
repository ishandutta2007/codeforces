#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
   int n, m;
   cin>>n>>m;
   int a[m] = {0};
     int only[n];
     string t[n];
     for (int i = 0; i<n; i++) cin>>t[i];
   for (int i = 0; i<n; i++) only[i] = -1;
   for (int i = 0; i<n; i++)
   {
       string s = t[i];
       for (int j = 0; j<m; j++)
       {
           if (s[j]=='1') a[j]++;
       }
   }

    for (int i = 0; i<n; i++)
   {
        string s = t[i];
       for (int j = 0; j<m; j++)
       {
           if ((s[j]=='1')&&(a[j]==1)) only[i] = j;
       }
   }

    bool check = false;
    for (int i = 0; i<n; i++) if (only[i]==-1) check = true;
    if (check) cout<<"YES";
    else cout<<"NO";
}