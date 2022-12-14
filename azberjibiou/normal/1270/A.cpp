#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int T;
int main()
{
    gibon
    cin >> T;
    while(T--)
    {
        int N, K1, K2, a=1, b=1;
        cin >> N >> K1 >> K2;
        for(int i=0;i<K1;i++)
        {
            int w;
            cin >> w;
            a=max(a, w);
        }
        for(int i=0;i<K2;i++)
        {
            int w;
            cin >> w;
            b=max(b, w);
        }
        if(a>b)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}