#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h,w;
	cin >> h >> w;
	string s[h];
	for(int i=0;i<h;i++) cin >> s[i];
	bool done=0;
	bool vis[h][w];
	memset(vis,0,sizeof vis);
	for(int o=1;o<h-1;o++)
    {
        for(int i=1;i<w-1;i++)
        {
            if(s[o][i]=='*'&&s[o+1][i]=='*'&&s[o][i+1]=='*'&&s[o-1][i]=='*'&&s[o][i-1]=='*'&&done==0)
            {
                for(int j=o;j<h;j++)
                {
                    if(s[j][i]=='*') vis[j][i]=1;
                    else break;
                }
                for(int j=o;j>=0;j--)
                {
                    if(s[j][i]=='*') vis[j][i]=1;
                    else break;
                }
                for(int j=i;j<w;j++)
                {
                    if(s[o][j]=='*') vis[o][j]=1;
                    else break;
                }
                for(int j=i;j>=0;j--)
                {
                    if(s[o][j]=='*') vis[o][j]=1;
                    else break;
                }
                done=1;
            }
        }
    }
	bool res=1;
    for(int o=0;o<h;o++)
    {
        for(int i=0;i<w;i++)
        {
            if(s[o][i]=='*'&&vis[o][i]==0) res=0;
        }
    }
    if(res&&done) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}