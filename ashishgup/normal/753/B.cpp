#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	string str;
	for(ll i=0;i<10;i++)
	{
		string s;
		char ch;
		for(ll j=0;j<4;j++)
		{
			ch=(char)(i+'0');
			s+=ch;
		}
		cout<<s<<endl;
		ll no1,no2;
		cin>>no1>>no2;
		if(no1==4)
		{
			return 0;
		}
		if(no1>0)
		{
			for(ll j=0;j<no1;j++)
			{
				str+=ch;
			}
		}		
	}
	sort(str.begin(),str.end());
	while(true)
	{
		cout<<str<<endl;
		ll no1,no2;
		cin>>no1>>no2;
		if(no1==4)
		{
			break;
		}
		next_permutation(str.begin(),str.end());
	}
    return 0;
}