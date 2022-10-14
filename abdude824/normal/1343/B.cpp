#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define v(type) vector<type>
#define int long long
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("aana.txt", "r", stdin);
		freopen("jaana.txt", "w", stdout);
	#endif
}	
int am(int x1,int y1,int x2,int y2)
{
	int m=(y1-y2)/(x1-x2);
	return m;
}
int cc(int x1,int y1,int x2,int y2,int m)
{
	int c=y2-m*x2;
	return c;
}
int32_t main() {
	aeh();
	W(t)
	{
		int n;cin>>n;
		if(n%4!=0)
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			int p=2;
			int ev[n/2];int od[n/2];
			for(int i=0;i<n/2;i++)
			{
				ev[i]=p;
				p+=2;
			}
			p-=2;int k=1;
			for(int i=0;i<n/2-1;i++)
			{
				od[i]=k;
				k+=2;
			}
			od[n/2-1]=p+n/2-1;
			for(int i=0;i<n/2;i++)
				cout<<ev[i]<<" ";
			for(int i=0;i<n/2;i++)
				cout<<od[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}