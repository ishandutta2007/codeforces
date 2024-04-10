#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

int n;
string s;
int x, y;

int U, D, R, L;

bool check(int l)
{
    int U1 = U;
    int D1 = D;
    int R1 = R;
    int L1 = L;
    for (int i = 0; i<l; i++) 
    {
        if (s[i]=='U') U1--;
        if (s[i]=='D') D1--;
        if (s[i]=='L') L1--;
        if (s[i]=='R') R1--;
    }
    if (abs(y+D1-U1)+abs(x+L1-R1)<=l) return true;
    for (int i = l; i<n; i++)
    {
        if (s[i-l]=='U') U1++;
        if (s[i-l]=='D') D1++;
        if (s[i-l]=='L') L1++;
        if (s[i-l]=='R') R1++;
        
        if (s[i]=='U') U1--;
        if (s[i]=='D') D1--;
        if (s[i]=='L') L1--;
        if (s[i]=='R') R1--;
        if (abs(y+D1-U1)+abs(x+L1-R1)<=l) return true;
    }
    return false;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>s;
    cin>>x>>y;
    if (abs(x)+abs(y)>n) {cout<<-1; return 0;}
    if ((abs(x)+abs(y))%2!=n%2) {cout<<-1; return 0;}
    U = 0;
    D = 0;
    R = 0;
    L = 0;
    for (int i = 0; i<n; i++) 
    {
        if (s[i]=='U') U++;
        if (s[i]=='D') D++;
        if (s[i]=='L') L++;
        if (s[i]=='R') R++;
    }
    
    if (U-D==y&&R-L==x) {cout<<0; return 0;}
    
    int l = 0; int r = n;
    
    while (r-l>1)
    {
        int cur = (r+l)/2;
        if (check(cur)) r = cur;
        else l = cur;
    }
    
    cout<<r;
    
}