#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N=1e5+5;

int store=1;
int trie[1200005][26];

int32_t main()
{
    IOS;
    memset(trie, -1, sizeof(trie));
    string s, good;
    cin>>s>>good;
    int n=s.size();
    int k;
    cin>>k;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int v=0;
        int cntbad=0;
        for(int j=i;j<n;j++)
        {
            if(good[s[j]-'a']=='0')
                cntbad++;
            if(cntbad>k)
                break;
            int cur=s[j]-'a';
            if(trie[v][cur]==-1)
            {
                ans++;
                trie[v][cur]=store++;
            }
            v=trie[v][cur];
        }
    }
    cout<<ans;
    return 0;
}