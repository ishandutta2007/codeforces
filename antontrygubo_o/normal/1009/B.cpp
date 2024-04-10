#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<char> kek;
    for (int i = 0; i<n; i++) if (s[i]!='1') kek.push_back(s[i]);
    int ones = n - kek.size();
    bool t = false;
    for (int i = 0; i<kek.size(); i++)
    {
        if (kek[i]=='2'&&t==false) {for (int j = 0; j<ones; j++) cout<<'1'; t = true;}
        cout<<kek[i];
    }
    if (t==false) {for (int j = 0; j<ones; j++) cout<<'1'; t = true;}
}