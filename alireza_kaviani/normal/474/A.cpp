#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

int index(string s,char c)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==c)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char a; cin >> a;
    int shift=(a=='R')?-1:+1;
    
    string s="qwertyuiopasdfghjkl;zxcvbnm,./";
    string s2 , ans="";
    cin >> s2;
    
    for(int i=0;i<s2.size();i++)
    {
        ans += s[index(s,s2[i])+shift];
    }
    cout << ans;
}