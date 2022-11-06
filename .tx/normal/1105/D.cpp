#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long MOD = 1e9+7;
pair<int,int> dx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long fastpow(long long x,long long k)
{
    if(!k)
        return 1;
    if(k & 1)
        return ((x * fastpow(x,k-1) % MOD) % MOD) % MOD;
    long long ans = fastpow(x,k/2);
    ans %= MOD;
    ans *= ans;
    ans %= MOD;
    return ans;
}
long long sumF(long long x)
{
    int s = 0;
    while(x)
        s += x%10,x /= 10;
    return s;
}
char arr[1005][1005];
int expandSpeed[10];
int playerLand[1005][1005];
int ans[10];
queue<pair<pair<int,int>, int> > myQue[10];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,p;
    cin >> n >> m >> p;
    for(int i = 1;i <= p;i++)
        cin >> expandSpeed[i];

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> arr[i][j];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(arr[i][j] >= '1' && arr[i][j] <= '9')
                myQue[arr[i][j] - '0'].push(make_pair(make_pair(i,j),expandSpeed[arr[i][j] - '0'])),playerLand[i][j] = arr[i][j] - '0';
        }
    }
    while(true)
    {
        int z = 0;
        for(int i = 1;i <= p;i++)
        {
            if(myQue[i].size())
                z = i;
            queue<pair<pair<int,int>, int> > tmp;
            while(myQue[i].size())
            {
                pair<pair<int,int>,int > curTop = myQue[i].front();
                myQue[i].pop();
                int xPos = curTop.first.first;
                int yPos = curTop.first.second;
                int curLevel = curTop.second;
                if(curLevel == 0)
                {
                    tmp.push(make_pair(make_pair(xPos,yPos),expandSpeed[i]));
                    continue;
                }
                for(int j = 0;j < 4;j++)
                {
                    int nXpos = xPos + dx[j].first;
                    int nYpos = yPos + dx[j].second;
                    if(nXpos >= 1 && nXpos <= n && nYpos >= 1 && nYpos <= m && arr[nXpos][nYpos] != '#' && playerLand[nXpos][nYpos] == 0)
                    {
                        playerLand[nXpos][nYpos] = i;
                        myQue[i].push(make_pair(make_pair(nXpos,nYpos),curLevel - 1));
                    }
                }
            }
            myQue[i] = tmp;
        }
        if(z == 0)
            break;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
            ans[playerLand[i][j]]++;
    }
    for(int i = 1;i <= p;i++)
        cout << ans[i] << " ";
    return 0;
}