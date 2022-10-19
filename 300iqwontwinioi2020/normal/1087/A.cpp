#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    string s, ss = "";
    cin>>s;
    int n = s.size();
    int k = (n - 1) / 2;
    ss = s[k];
    for (int i = 1; i <= n; i++){
        if (i + k < n)
            ss += s[i + k];
        if (k - i >= 0)
            ss += s[k - i];
    }
    cout<<ss<<endl;
    return 0;
}