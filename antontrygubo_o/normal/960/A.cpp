#include <bits/stdc++.h>

using namespace std;
int main() 
{
string s;
cin>>s;
int a = 0;
int b = 0;
int c = 0;
int len = s.length();
int idx = 0;
while (idx<len&&s[idx]=='a') {a++; idx++;}
while (idx<len&&s[idx]=='b') {b++; idx++;}
while (idx<len&&s[idx]=='c') {c++; idx++;}
if (idx!=len) {cout<<"NO"; return 0;}
else 
{
    if (a==0||b==0||c==0) {cout<<"NO"; return 0;}
    if (c==a||c==b) {cout<<"YES"; return 0;}
    else {cout<<"NO"; return 0;}
}
}