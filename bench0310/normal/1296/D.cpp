#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        int h;
        cin >> h;
        h%=(a+b);
        if(h==0) h=a+b;
        v[i]=(h+a-1)/a-1;
    }
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(k<v[i]) break;
        res++;
        k-=v[i];
    }
    cout << res << "\n";
    return 0;
}