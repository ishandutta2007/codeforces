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
        vector<int> v[2];
        for(int i=1;i<=2*n;i++)
        {
            int a;
            cin >> a;
            v[a&1].push_back(i);
        }
        int c=n-1;
        for(int o=0;o<2;o++)
        {
            for(int i=0;i+1<(int)v[o].size();i+=2)
            {
                if(c==0) break;
                cout << v[o][i] << " " << v[o][i+1] << "\n";
                c--;
            }
        }
    }
    return 0;
}