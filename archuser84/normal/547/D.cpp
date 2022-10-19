#include <bits/stdc++.h>
#define ll long long
#define Loop(x,a,b) for(int x = a; x < b; x++)
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int m;
const int n = 400002;
const int ezaf[2] = {200000,400001};
vector<int> A[n];
map<pair<int, int>, __int8> color;
int p[n] = { 0 };

void Color(int s)
{
	bool cing = 0;
	int u = s;
	while(true)
	{
		bool flag = false;
		Loop(i,p[u],A[u].size())
		{
			int v = A[u][i];
			if(color[{u,v}] == 0)
			{
				flag = true;
				color[{u,v}] = (int)cing + 1;
				color[{v,u}] = (int)cing + 1;
				cing = !cing;
				p[u] = i + 1;
				u = v;
				break;
			}
		}
		if(!flag)
			break;
	}
}

int main()
{
	FAST;
	pair<int, int> dots[200000];
	cin >> m;
	Loop(i,0,m)
	{
		int u,v;
		cin >> u >> v;
		u--; v--; v+=200001;
		dots[i] = {u, v};
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i,0,n/2 - 1)
	{
		if(A[i].size() % 2)
		{
			A[i].push_back(ezaf[1]);
			A[ezaf[1]].push_back(i);
		}
	}
	Loop(i,n/2,n - 1)
	{
		if(A[i].size() % 2)
		{
			A[i].push_back(ezaf[0]);
			A[ezaf[0]].push_back(i);
		}
	}
	if(A[ezaf[0]].size() % 2)
	{
		A[ezaf[0]].push_back(ezaf[1]);
		A[ezaf[1]].push_back(ezaf[0]);
	}
	Loop(u,0,n)
	{
		Color(u);
	}
	Loop(i,0,m)
	{
		int u = dots[i].first;
		int v = dots[i].second;
		if(color[{u,v}] == 1)
			cout << 'r';
		else
			cout << 'b';
	}
}