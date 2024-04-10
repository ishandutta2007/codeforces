#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;
const int off=250;

int startx, starty, n, d;
int dx[N], dy[N];
int cache[N][N]; 

int dp(int x, int y) //Checks if point X, Y is a winning state
{
	if(x*x + y*y > d*d)
		return 1;
	int &cur=cache[x+off][y+off];
	if(cur!=-1)
		return cur;
	cur=0;
	for(int i=1;i<=n;i++)
	{
		if(!dp(x+dx[i], y+dy[i]))
			cur=1;
	}
	return cur;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
   	cin>>startx>>starty>>n>>d;
   	for(int i=1;i<=n;i++)
   	{
   		cin>>dx[i]>>dy[i];
   	}
   	if(dp(startx, starty))
   		cout<<"Anton";
   	else
   		cout<<"Dasha";
    return 0;
}