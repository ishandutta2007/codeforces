#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> c(2,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if((a-i)&1) c[i&1]++;
        }
        if(c[0]==c[1]) cout << c[0] << "\n";
        else cout << "-1\n";
    }
    return 0;
}