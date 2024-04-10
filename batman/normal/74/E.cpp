#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)6)

ll a[N][N];
vector <string> res;

void _swap1(ll i,ll j)
{
	string x="";x+=(char)(i+'1');
	string y="";y+=(char)(j+'1');
	for(int p=0;p<3;p++)
		res.push_back("U"+y),
		res.push_back("L"+x),
		res.push_back("U"+y),
		res.push_back("R"+x);
	res.push_back("U"+y);
}

void _swap2(ll i,ll j)
{
	string x="";x+=(char)(i+'1');
	string y="";y+=(char)(j+'1');
	for(int p=0;p<3;p++)
		res.push_back("R"+x),
		res.push_back("U"+y),
		res.push_back("R"+x),
		res.push_back("D"+y);
	res.push_back("R"+x);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			char c;
			cin>>c;
			if(c>='0' && c<='9')a[i][j]=c-'0';
			else a[i][j]=c-'A'+10;
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			ll now_i=-1,now_j=-1;
			for(int i2=0;i2<N;i2++)
				for(int j2=0;j2<N;j2++)
					if(a[i2][j2]==i*N+j)
					{
						now_i=i2;
						now_j=j2;
						break;
					}
			while(now_j!=j)
			{
				ll nxt=(now_j-1+N)%N;
				swap(a[now_i][now_j],a[now_i][nxt]);
				_swap1(now_i,nxt);
				now_j=nxt;
			}
			while(now_i!=i)
			{
				ll nxt=(now_i-1+N)%N;
				swap(a[now_i][now_j],a[nxt][now_j]);
				_swap2(nxt,now_j);
				now_i=nxt;
			}
		}
	cout<<res.size()<<"\n";
	for(auto u:res)cout<<u<<"\n";
	return 0;
}