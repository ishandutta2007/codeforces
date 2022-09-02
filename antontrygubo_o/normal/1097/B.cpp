#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(string a, string b)
{
    return (a[0]==b[0]||a[1]==b[1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int> > a(n+1, vector<int>(360));
    a[0][0] = 1;
    int temp;
    for (int i = 0; i<n; i++)
    {
        cin>>temp;
        for (int j = 0; j<360; j++) if (a[i][j])
        {
            a[i+1][(j+temp)%360] = 1;
            a[i+1][(j+360-temp)%360] = 1;
        }
    }
    if (a[n][0]) cout<<"YES";
    else cout<<"NO";
}