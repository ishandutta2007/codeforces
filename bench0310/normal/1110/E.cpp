#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> c(n),t(n);
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<n;i++) cin >> t[i];
    bool good=1;
    if(c[0]!=t[0]||c[n-1]!=t[n-1]) good=0;
    vector<int> a,b;
    for(int i=1;i<n;i++)
    {
        a.push_back(c[i]-c[i-1]);
        b.push_back(t[i]-t[i-1]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n-1;i++) if(a[i]!=b[i]) good=0;
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}