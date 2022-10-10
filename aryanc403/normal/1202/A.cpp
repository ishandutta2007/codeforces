//https://codeforces.com/contest/1202/submission/58437929

#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MOD 1000000007
#define MOD2 1000000009
#define INF 2000000000
#define DESPACITO 10000000000000
#define PI acos(-1)
#define E 998244353
#define pb push_back
#define mp make_pair
#define double long double
#define pdd pair<double,double>
#define ll long long
using namespace std;
//using namespace __gnu_pbds;
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	IOS;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin >> t;
	while(t--)
	{
		string s,t;
		cin >> s;
		cin >> t;
		int pos1=0,pos2=-1;
		for(int i=t.length()-1;i>=0;i--)
		{
			if(t[i]=='1')
			{
				pos2=t.length()-1-i;
				break;
			}
		}
		for(int i=s.length()-1-pos2;i>=0;i--)
		{
			if(s[i]=='1')
				break;
			pos1++;
		}
		cout << pos1 << "\n";
	}	
}