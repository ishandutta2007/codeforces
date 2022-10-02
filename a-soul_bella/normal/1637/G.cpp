#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[100005],qwq;
vector <pair<int,int> > v; 
inline void op(int x,int y)
{
	v.push_back({x,y});
	++cnt[x+y],++cnt[max(x-y,y-x)];
	--cnt[x],--cnt[y];
}
inline int lowbit(int x)
{
	return x&-x;
}
inline void print()
{
	for(int i=0;i<=qwq;i++)
	{
		for(int j=0;j<cnt[i];j++)
			cout << i << " ";
	}
	cout << "\n";
}
signed main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n==2)
		{
			cout << "-1\n";
			continue;
		}
		qwq=1;
		while(qwq<n) qwq*=2;
		for(int i=1;i<=qwq;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[i]=1;
	//	print();
		for(int j=1;j<qwq;j*=2)
		{
			for(int i=qwq;i>=2;i/=2)
			{
				for(int x=i-j;x>0;x-=j)
					if(lowbit(x)==j) while(x!=i-x&&	cnt[x]&&cnt[i-x]) op(x,i-x);
			}
		//	print();
		}
		if(!cnt[0]) for(int i=1;i<qwq;i++)
			if(cnt[i]>1) op(i,i);
		for(int i=1;i<qwq;i++)
			while(cnt[i]) op(i,0),op(i,i);
		while(cnt[0]) op(qwq,0);
	//	print();
		cout << v.size() << "\n";
		for(auto t:v) cout << t.first << " " << t.second << "\n";
		v.clear();
	}
	return 0;
}