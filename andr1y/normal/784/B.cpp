#include <bits/stdc++.h>
using namespace std;
string dec2hex(unsigned long long i)
{
    stringstream ss;
    ss << hex << uppercase << i;
    return ss.str();
}
int main(){
    int a;
    cin >> a;
    string s = dec2hex(a);
    int c = 0;
    for(int i=0;i<s.length();i++) c+=((s[i]=='0' || s[i]=='4' || s[i]=='6' || s[i]=='9' || s[i]=='A' || s[i]=='D')?1:((s[i] == 'B' || s[i]=='8')?2:0));
    cout << c;
}