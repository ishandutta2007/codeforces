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
        string a;
        cin >> a;
        int res=0;
        set<array<array<int,2>,2>> s;
        int x=0,y=0;
        for(char c:a)
        {
            array<int,2> p={x,y};
            if(c=='N') y++;
            else if(c=='S') y--;
            else if(c=='W') x--;
            else if(c=='E') x++;
            array<int,2> r={x,y};
            if(p>r) swap(p,r);
            res++;
            if(s.find({p,r})==s.end()) res+=4;
            s.insert({p,r});
        }
        cout << res << "\n";
    }
    return 0;
}