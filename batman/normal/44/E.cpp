#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (220)
#define INF ((ll)1e9)

ll k,a,b;
string s;
bool mark[N][N];
ll dp[N][N];
vector <string> ans;

int main()
{
   	cin>>k>>a>>b>>s;
   	mark[0][0]=1;
   	for(int i=a;i<=b;i++)
   		for(int q=i;q<N;q++)
   			for(int p=1;p<N;p++)
   				if(mark[q-i][p-1])
   					dp[q][p]=i,mark[q][p]=1;		
   	ll n=s.size(),p=0;
	while(n)
	{
		if(!mark[n][k])return cout<<"No solution",0;
		string ex="";
		for(int j=0;j<dp[n][k];j++,p++)
			ex+=s[p];
		ans.push_back(ex);
		n-=dp[n][k--];
	}	
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";		
    return 0;
}