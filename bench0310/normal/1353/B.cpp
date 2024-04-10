#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        multiset<int> a,b;
        for(int i=0;i<2*n;i++)
        {
            int x;
            cin >> x;
            if(i<n) a.insert(x);
            else b.insert(x);
        }
        for(int i=0;i<k;i++)
        {
            int x=(*a.begin());
            int y=(*b.rbegin());
            if(x<y)
            {
                a.erase(a.find(x));
                b.erase(b.find(y));
                a.insert(y);
                b.insert(x);
            }
            else break;
        }
        int res=0;
        for(int x:a) res+=x;
        cout << res << "\n";
    }
    return 0;
}