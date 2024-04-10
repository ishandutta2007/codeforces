#include <bits/stdc++.h>

using namespace std;

long long n, a=0, b=0, c=0, d=0;
long long ki;
string s1, s2;

int main()
{
    cin >> n;
    cin >> s1 >> s2;
    for(int i=0;i<n;i++) {
        if(s1[i]=='0' && s2[i]=='0') a++;
        if(s1[i]=='1' && s2[i]=='0') b++;
        if(s1[i]=='0' && s2[i]=='1') c++;
        if(s1[i]=='1' && s2[i]=='1') d++;
    }

    cout << a*b+a*d+b*c << endl;
    return 0;
}