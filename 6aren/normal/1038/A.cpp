#include <bits/stdc++.h>
using namespace std;
int n, k, a[26];
string s;
int main(){
    cin >> n >> k;
    cin >> s;
    for (int i=0; i<n; i++){
        int u=(int) (s[i]-'A');
        a[u]++;
    }
    int mini=1e9;
    for (int i=0; i<k; i++){
        mini=min(mini, a[i]);
    }
    cout << k*mini;
}