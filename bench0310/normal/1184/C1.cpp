#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<4*n+1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    for(int o=0;o<=50;o++)
    {
        for(int i=0;i<=50;i++)
        {
            for(int a=2;a<=50;a++)
            {
                int x1=i,x2=i+a,y1=o,y2=o+a;
                vector<bool> vis(4*n+1,0);
                int cnt=0;
                for(int j=0;j<4*n+1;j++)
                {
                    if((v[j].first==x1||v[j].first==x2)&&y1<=v[j].second&&v[j].second<=y2)
                    {
                        vis[j]=1;
                        cnt++;
                        continue;
                    }
                    if((v[j].second==y1||v[j].second==y2)&&x1<=v[j].first&&v[j].first<=x2)
                    {
                        vis[j]=1;
                        cnt++;
                    }
                }
                if(cnt==4*n)
                {
                    for(int j=0;j<4*n+1;j++)
                    {
                        if(vis[j]==0)
                        {
                            cout << v[j].first << " " << v[j].second << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
	return 0;
}