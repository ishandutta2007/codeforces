#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(string a, string b)
{
    return (a[0]==b[0]||a[1]==b[1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    string s; cin>>s;
    string temp;
    for (int i = 0; i<5; i++)
    {
        cin>>temp;
        if (check(s, temp)) {cout<<"YES"; return 0;}
    }
    cout<<"NO";
}