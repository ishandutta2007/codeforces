#include<bits/stdc++.h>

using namespace std;

#define v(type) vector<type>
#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x

void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
//rule 1:line gap after each cin and cout
// rule 2:line gap afte each if statement
//rule 3: line gap after each  loop
int32_t main()
{
	aeh();
	int n;cin>>n;

	v(int) a(n);v(int) b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}	
	sort(b.begin(),b.end());
	map<int,int>mp;
	for(int i=0;i<n;i++)
		mp[b[i]]=i;
	int l=-1,r=-1;
	for(int i=0;i<n;i++)
	{
		a[i]=mp[a[i]];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=i)
			{l=i;break;}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]!=i)
		{
			r=i;break;
		}
	}
	if(l==-1||r==-1)
		cout<<"yes\n1 1";
	else{
		reverse(a.begin()+l,a.begin()+r+1);
		int fl=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=i)
				{fl=1;cout<<"no"<<endl;break;}
		}
		if(fl==0)
		{
			cout<<"yes\n"<<l+1<<" "<<r+1<<endl;
		}
	}	
}