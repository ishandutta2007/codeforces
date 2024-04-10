#include<bits/stdc++.h>
using namespace std;

long long result (long long n, string s)
{
    long long len = s.length();
    map<char, int> counter;
    for (int i = 65; i<=90; i++) counter[char(i)] = 0;
    for (int i = 97; i<=122; i++) counter[char(i)] = 0;
    for (int i = 0; i<len; i++) counter[s[i]]++;
    int maxx = 0;
    for (int i = 65; i<=90; i++) maxx = max(maxx, counter[char(i)]);
    for (int i = 97; i<=122; i++) maxx = max(maxx, counter[char(i)]);
    if (maxx==len&&n==1) return len-1;
    return min(len, maxx+n);
}

int main()
{
long long n;
cin>>n;
string Kuro, Shiro, Katie;
cin>>Kuro>>Shiro>>Katie;
long long a, b, c;
a = result(n, Kuro);
b = result(n, Shiro);
c = result(n, Katie);
if (a>b&&a>c) cout<<"Kuro";
else if (b>a&&b>c) cout<<"Shiro";
else if (c>a&&c>b) cout<<"Katie";
else cout<<"Draw";

}