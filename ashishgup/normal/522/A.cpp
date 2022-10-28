#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back

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
	multimap <string,string> mp;
	for(ll z=0;z<=n;z++)
	{
		string s;
		getline(cin,s);
		ll index=s.find_first_of(' ',0);
		ll index2=s.find_first_of(' ',index+1);
		string s1=s.substr(0,index);
		string s2=s.substr(index2+1);
		ll size1=s1.size();
		ll size2=s2.size();
		for(ll i=0;i<size1;i++)
		{
			s1[i]=tolower(s1[i]);
		}
		for(ll i=0;i<size2;i++)
		{
			s2[i]=tolower(s2[i]);
		}	
		//cout<<s1<<" "<<s2<<endl;	
		mp.insert(make_pair(s2,s1));
	}
	map<string, ll> levels;
	levels["polycarp"]=1;
	queue <string> q;
	q.push("polycarp");
	//map<string, bool> visited;
	while(!q.empty())
	{
		string temp=q.front();
		q.pop();
		pair <multimap<string,string>::iterator, multimap<string,string>::iterator> ret;
    	ret = mp.equal_range(temp);
    	std::multimap<string,string>::iterator it=ret.first;
		while(it!=ret.second)
		{
			//cout<<(*it).second<<endl;
			if(levels.find((*it).second)==levels.end())
			{
				levels[(*it).second]=levels[temp]+1;
				q.push((*it).second);
			}
			it++;
		}
	}
	ll max1=2;
	map<string, ll>::iterator it=levels.begin();
	while(it!=levels.end())
	{
		ll temp=(*it).second;
		if(temp>max1)
		{
			max1=temp;
		}
		it++;
	}
	cout<<max1;
	return 0;
}