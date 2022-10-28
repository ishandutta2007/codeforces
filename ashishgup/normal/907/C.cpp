#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int32_t main()
{
    IOS;
    int ans=0;
    set<char> pos;
    for(char ch='a';ch<='z';ch++)
    {
        pos.insert(ch);
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='!')
        {
            string s;
            cin>>s;
            set<char> cur;
            for(auto it:s)
                cur.insert(it);
            if(pos.size()==1)
            {
                ans++;
            }
            set<char> to_remove;
            for(auto it:pos)
            {
                if(cur.find(it)==cur.end())
                    to_remove.insert(it);
            }
            for(auto it:to_remove)
                pos.erase(it);
        }
        else if(ch=='.')
        {
            string s;
            cin>>s;
            set<char> cur;
            for(auto it:s)
            {
                cur.insert(it);
            }
            set<char> to_remove;
            for(auto it:pos)
            {
                if(cur.find(it)!=cur.end())
                    to_remove.insert(it);
            }
            for(auto it:to_remove)
                pos.erase(it);
        }
        else
        {
            char ch;
            cin>>ch;
            if(pos.size()==1)
            {
                if(!pos.count(ch))
                    ans++;
            }
            if(i!=n)
            {
                pos.erase(ch);
            }
        }
    }
    cout<<ans;
}