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
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int res=-1;
        for(int i=1023;i>0;i--)
        {
            set<int> a;
            for(int x:s) a.insert(x^i);
            if(a==s) res=i;
        }
        cout << res << "\n";
    }
    return 0;
}