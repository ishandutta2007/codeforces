#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    vector <int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==a[i+1])
        {
            ans++;
        }
    }

    cout << ans;
}