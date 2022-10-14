#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vs vector<string>
#define int long long int
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
int32_t main() {
	aeh();
	W(t)
	{
		int x,y;cin>>x>>y;
		int a,b;cin>>a>>b;
		int diff=abs(x-y);
		int small=(x<y)?x:y;
		int res=(a*diff)+(b*small);
		int res2=a*x+a*y;
		int fres=(res2<res)?res2:res;
		cout<<fres<<endl;
	}
	return 0;
}