#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define ll long long
using namespace std;
char S[101010], T[101010];
vector <int> v[26];
int main()
{
    gibon
    int o;
    cin >> o;
    while(o--)
    {
        cin >> S;
        cin >> T;
        for(int i=0;i<26;i++)   v[i].clear();
        int lent=strlen(T), lenS=strlen(S);
        int tcur=0, scur=-1;
        for(int i=0;i<lenS;i++)
        {
            int tmp=S[i]-'a';
            v[tmp].push_back(i);
        }
        int ans=1;
        bool jogun=false;
        for(int i=0;i<lent;i++)
        {
            int tmp=T[i]-'a';
            if(v[tmp].empty())
                jogun=true;
        }
        if(jogun)
        {
            cout << -1 << '\n';
            continue;
        }
        while(tcur!=lent)
        {
            int now=T[tcur]-'a';
            int nxt=lower_bound(v[now].begin(), v[now].end(), scur+1)-v[now].begin();
            if(nxt>=(int)v[now].size())
            {
                ans++;
                scur=-1;
            }
            else
            {
                scur=v[now][nxt];
                tcur++;
            }
        }
        cout << ans << '\n';
    }
}