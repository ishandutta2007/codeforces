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

void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}




int32_t main()
{
	aeh();
	int n,m;cin>>m>>n;
	int max=n+1;int min=(n%2==0)?(n/2)-1:(n-1)/2;
	if(m<min||m>max)
		cout<<"-1"<<endl;
	else{
		// string s;
		// for(int i=0;i<n+min;i++)
		// {
		// 	if((i+1)%3==0)
		// 		s+='0';
		// 	else s+='1';
		// }
		// int rem=m-min;
		// for(int i=0;i<s.size()&&rem>0;i++)
		// {
		// 	if(s[i]=='1'&&s[i+1]!='0')
		// 	{
		// 		s.insert(i+1,"0");
		// 		rem--;
		// 	}
		// }
		// if(rem>0)
		// {
		// 	s.insert(0,"0");rem--;
		// 	if(rem>0)
		// 		s.insert(s.size()-1,"0");
		// }
		// cout<<s<<endl;
		int arr[2*n+1];
		for(int i=0;i<2*n+1;i++)
			arr[i]=-1;
		for(int i=1;i<2*n+1;i+=2)
			arr[i]=1;
		for(int i=4;i<2*n-1;i+=4)
			arr[i]=0;
		int rem=m-min;
		for(int i=0;i<2*n+1&&rem>0;i+=2)
		{
			if(arr[i]==0)
				continue;
			else{
				arr[i]=0;
				rem--;
			}
		}
		for(int i=0;i<2*n+1;i++)
		{
			if(arr[i]!=-1)
				cout<<arr[i];
		}

	}

}