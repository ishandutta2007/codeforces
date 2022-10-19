#include <bits/stdc++.h>
using namespace std;
struct node
{
    int mod;
    int sum;
    string a;
};
bool vis[505][6005];
int d,s;
queue <node> q;

int main()
{
    cin >> d >> s;
    q.push({0,0,""});
    vis[0][0]=true;
    while (!q.empty())
    {
        node u=q.front();
        q.pop();
        if (u.sum > s) continue;
        if (u.mod==0 && u.sum==s)
        {
            cout << u.a;
            return 0;
        }
        for (int i=0;i<=9;i++)
        {
            int aa=(u.mod*10+i)%d;
            int bb=u.sum+i;
            if (!vis[aa][bb])
            {
                vis[aa][bb]=true;
                q.push({aa,bb,u.a+(char)(i+'0')});
            }
        }
    }
    cout << -1;
}