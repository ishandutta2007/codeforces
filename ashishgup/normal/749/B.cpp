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
    ll a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    ll d1,d2,e1,e2,f1,f2;
    d1=a1+b1-c1;
    d2=a2+b2-c2;
    e1=a1+c1-b1;
    e2=a2+c2-b2;
    f1=b1+c1-a1;
    f2=b2+c2-a2;
    ll k=3;
    if(d1==e1&&d2==e2)
    {
    	if(d1==f1&&d2==f2)
    	{
    		cout<<"1"<<endl;
    		cout<<d1<<" "<<d2<<endl;
		}
		else
		{
			cout<<"2"<<endl;
			cout<<d1<<" "<<d2<<endl;
			cout<<f1<<" "<<f2<<endl;
		}
	}
	else if(d1==f1&&d2==f2)
	{
		cout<<"2"<<endl;
		cout<<d1<<" "<<d2<<endl;
		cout<<e1<<" "<<e2<<endl;
	}
	else if(e1==f1&&e2==f2)
	{
		cout<<"2"<<endl;
		cout<<d1<<" "<<d2<<endl;
		cout<<e1<<" "<<e2<<endl;
	}
	else
	{
		cout<<"3"<<endl;
		cout<<d1<<" "<<d2<<endl;
		cout<<e1<<" "<<e2<<endl;
		cout<<f1<<" "<<f2<<endl;
	}
    return 0;
}