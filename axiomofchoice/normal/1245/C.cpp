#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 100010
#define inf 1e9
int T,n,a[100010],dp[100010];
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	s='.'+s+'.';
	repeat(i,0,s.size()-1){
		if(s[i]=='u' && s[i+1]=='u')a[i]=a[i+1]=1;
		else if(s[i]=='n' && s[i+1]=='n')a[i]=a[i+1]=2;
	}
	dp[0]=dp[1]=1;
	repeat(i,2,s.size()){
		dp[i]=dp[i-1];
		if(a[i]>0 && a[i]==a[i-1])
			dp[i]+=dp[i-2];
		dp[i]%=1000000007;
	}
	bool f=true;
	repeat(i,0,s.size())if(s[i]=='m' || s[i]=='w')f=false;
	cout<<dp[s.size()-1]*f<<endl;
	return 0;
}