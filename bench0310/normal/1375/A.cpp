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
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if((a<0&&(i%2)==0)||(a>0&&(i%2)==1)) a=-a;
            cout << a << " \n"[i==n-1];
        }
    }
    return 0;
}