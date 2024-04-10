#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(string s)
{
    bool check = true;
    int n = s.length();
    for (int i = 0; i<s.length(); i++) 
    {
        int t = int(s[i]) - int(s[n-1-i]);
        t = fabs(t);
        t = fabs(t-1);
        if (t!=1) check = false;
    }
    if (check) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   int temp;
   int n;
   cin>>n;
   string s;
   for (int i = 0; i<n; i++)
   {
       cin>>temp;
       cin>>s;
       solve(s);
   }

}