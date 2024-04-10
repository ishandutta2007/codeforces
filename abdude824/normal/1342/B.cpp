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
	
	W(t)
	{
		string t;cin>>t;
		int n=t.size();int fl=0;
		fi(n)
		{
			if(t[i]!=t[0])
			{
				fl=1;
				break;
			}
		}
		if(fl==0)
		{
			cout<<t<<endl;
		}
		else{
			fi(n)
			{
				cout<<"10";
			}
			cout<<endl;
		}
	}
	return 0;
}