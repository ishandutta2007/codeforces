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
		int k=2;int x;
		while(true)
		{
			if(n%((int)pow(2,k)-1)==0)
			{
				x=n/(pow(2,k)-1);
				break;
			}
			k++;
		}
		cout<<x<<"\n";
	}
	return 0;
}