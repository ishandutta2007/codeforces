#include <bits/stdc++.h>
using namespace std;

const char similar[5] = {'1', 'i', 'I', 'l', 'L'};
const char similar2[3] = {'0', 'o', 'O'};

bool completter (char a, char b)
{
    if (int(a) == int (b)) return true;
    if (int(a)>int(b)) swap(a, b);
    if ((int(a)>=65)&&(int(a)<=90)&&(int(a)+32==int(b))) return true;
    
    bool in1 = false;
    bool in2 = false;
    for (int i = 0; i<5; i++) if (similar[i]==a) in1 = true;
    for (int i = 0; i<5; i++) if (similar[i]==b) in2 = true;
    if ((in2)&&(in1)) return true;
    
    in1 = false;
    in2 = false;
    for (int i = 0; i<3; i++) if (similar2[i]==a) in1 = true;
    for (int i = 0; i<3; i++) if (similar2[i]==b) in2 = true;
    if ((in2)&&(in1)) return true;
    
    return false;
}

bool compstr (string a, string b)
{
    if (a.length()!=b.length()) return false;
    int k = a.length();
    bool state = true;
    for (int i = 0; i<k; i++) if (!completter(a[i], b[i])) state = false;
    return state;
}

int main()
{
string my;
cin>>my;
int n;
cin>>n;
string kek[n];
for (int i = 0; i<n; i++) cin>>kek[i];
bool st = true;
for (int i = 0; i<n; i++) if (compstr(my, kek[i])) st = false;
if (st) cout<<"Yes";
else cout<<"No";

}