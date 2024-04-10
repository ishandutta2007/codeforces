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
        string s;
        cin >> s;
        int n=s.size();
        map<int,int> m;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='+') sum++;
            else
            {
                sum--;
                if(m.find(sum)==m.end()) m[sum]=i+1;
            }
        }
        ll res=0;
        for(int i=0;;i++)
        {
            if(m.find(-i-1)==m.end())
            {
                res+=n;
                break;
            }
            else res+=m[-i-1];
        }
        cout << res << "\n";
    }
    return 0;
}