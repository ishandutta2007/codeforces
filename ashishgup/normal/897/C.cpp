#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int INF=2e18;

string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string left1="What are you doing while sending \"";
string middle="\"? Are you busy? Will you send \"";
string right1="\"?";

int len[N];

char rec(int n, int k)
{
	if(k>len[n])
		return '.';
	if(n==0)
		return s[k-1];
	int cursize=left1.size();
	if(k<=cursize)
		return left1[k-1];
	cursize+=len[n-1];
	if(k<=cursize)
		return rec(n-1, k-(cursize-len[n-1]));
	cursize+=middle.size();
	if(k<=cursize)
	{
		return middle[k-(cursize-middle.size())-1];
	}
	cursize+=len[n-1];
	if(k<=cursize)
	{
		return rec(n-1, k-(cursize-len[n-1]));
	}
	return right1[k-cursize-1];
}

int32_t main()
{
	IOS;
	len[0]=s.size();
	for(int i=1;i<N;i++)
	{
		len[i]=2 * len[i-1] + left1.size() + middle.size() + right1.size();
		len[i]=min(len[i], INF);
	}
	int q;
	cin>>q;
	while(q--)
	{
		int n, k;
		cin>>n>>k;
		cout<<rec(n ,k);
	}	
	return 0;
}