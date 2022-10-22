#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 300005;
vector<int>mp[maxn];
int color[maxn];
vector <int> vec[maxn];
bool visit[maxn];
const int mod=998244353;
 
bool bfs(int s)
{
    color[s] = 0; //10
    queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i = 0; i < (int)mp[s].size(); i ++) {
          int t = mp[s][i];
          if (color[t] == -1) color[t] = !color[s], q.push(t); //
                                                   //
          if (color[t] == color[s]) { //
            return false;
          }
        }
    }
    return true;
}

pair<int,int> go(int x,int d)
{
//	cout<<x<<' '<<d<<endl;
	int res1=(d&1),res2=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(visit[vec[x][i]]) continue;
		visit[vec[x][i]]=true;
		pair<int,int> t=go(vec[x][i],d+1);
		res1+=t.first;
		res2+=t.second;
	}
	return make_pair(res1,res2);
}
#define ll long long
ll ksm(ll basic,int x)
{
//	cout<<mod<<endl;
	ll res=1;
	while(x)
	{
		if(x&1)
		{
			res*=basic;
			res%=mod;
		}
		basic*=basic;
		basic%=mod;
		x>>=1;
	}
//	cout<<res<<' '<<mod<<endl;
	return res;
}
int main()
{
    int n, m;
    int T;
    cin>>T;
    while (T--)
    {
    	scanf("%d%d",&n,&m);
    	for(int i=0;i<n;i++)
    	{
    		visit[i]=false;
    		vec[i].clear();
		}
        for (int i = 1; i <= n; i ++) mp[i].clear();
        memset(color, -1, (n+1)*sizeof(color[0]));
        for (int i = 0; i < m; i ++) {
            int x, y;
            scanf("%d%d",&x,&y);
//            cin >> x>>y;
            mp[x].push_back(y); //
            mp[y].push_back(x);
            x--;
            y--;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        int flag = true; //
        for (int i = 1; i <= n; i ++) {
            if (color[i] == -1 && !bfs(i)) { //
                    //
                flag = false;
                break;
            }
        }
        if (!flag){
        	printf("0\n");
        	continue;
		}
//		cout<<ksm(2,2)<<endl;
		ll res=1;
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				visit[i]=true;
				pair<int,int> t=go(i,0);
//				cout<<t.first<<'-'<<t.second<<endl;
				res*=ksm(2,t.first)+ksm(2,t.second-t.first);
				res%=mod;
			}
		}
		printf("%d\n",res);
//        else
//            cout <<"yes"<<endl;
    }
    return 0;
}