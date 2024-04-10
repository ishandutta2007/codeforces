#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll count=0;
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	char ch1=s[0];
	char ch2='?';
	char op1;
	if(ch1=='U')
	{
    	op1='D';
	}
	if(ch1=='L')
	{
		op1='R';
	}
	if(ch1=='R')
	{
		op1='L';
	}
	if(ch1=='D')
	{
		op1='U';
	}
	char op2;
	for(ll i=1;i<n-1;i++)
	{
		/*if(i==16)
		{
			cout<<s[i]<<" "<<ch1<<" "<<op1<<" "<<ch2<<" "<<op2<<endl;
		}*/
		if(s[i]==ch1||s[i]==ch2)
		{
			continue;
		}
		if(s[i]==op1)
		{
			ch1=op1;
			if(ch1=='U')
			{
				op1='D';
			}
			if(ch1=='L')
			{
				op1='R';
			}
			if(ch1=='R')
			{
				op1='L';
			}
			if(ch1=='D')
			{
				op1='U';
			}
			ch2='?';
			op2='?';
			count++;
			//cout<<i<<endl;
		}
		else
		{
			if(ch2=='?')
			{
				ch2=s[i];
				if(ch2=='U')
				{
					op2='D';
				}
				if(ch2=='L')
				{
					op2='R';
				}
				if(ch2=='R')
				{
					op2='L';
				}
				if(ch2=='D')
				{
					op2='U';
				}
			}
			else
			{
				if(s[i]==op2)
				{
					ch1=op2;
					if(ch1=='U')
					{
						op1='D';
					}
					if(ch1=='L')
					{
						op1='R';
					}
					if(ch1=='R')
					{
						op1='L';
					}
					if(ch1=='D')
					{
						op1='U';
					}
					ch2='?';
					op2='?';
					count++;
					//cout<<i<<endl;
				}
			}
		}
	}
	//cout<<ch1<<" "<<ch2<<" "<<op1<<" "<<op2;
	count++;
	if(s[n-1]==op1||s[n-1]==op2)
	{
		count++;
	}
	cout<<count;
	return 0;
}