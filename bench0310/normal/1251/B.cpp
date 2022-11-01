#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        int b=0;
        bool odd=0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            if(s.size()&1) odd=1;
            for(char a:s) b+=(a=='0');
        }
        if(odd||(b%2)==0) cout << n << endl;
        else cout << n-1 << endl;
    }
    return 0;
}