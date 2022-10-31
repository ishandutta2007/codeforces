#include <bits/stdc++.h>
#define int unsigned long long
#define endl '\n'
using namespace std;
main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while(s[i] == s[i+1]) i++;
    int j = n-1;
    while(s[j] == s[j-1]) j--;
    if(s[i] != s[j]) cout << (2+i+n-j)%998244353ll;
    else cout << (2+i+n-j + (i+1)*(n-j))%998244353ll;
}