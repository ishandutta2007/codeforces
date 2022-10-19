#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

int main()
{
    int n;
    cin >> n;
    
    int y=false;
    string ans="";
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin >> s;
    	
    	string s2="";
    	s2.push_back(s[0]);
    	s2.push_back(s[1]);
    	if(s2=="OO" && !y)
    	{
    		y=true;
    		ans+="++|";
    	}
    	else
    	{
    		ans+=s2+"|";
    	}
    	
    	s2="";
    	s2.push_back(s[3]);
    	s2.push_back(s[4]);
    	if(s2=="OO" && !y)
    	{
    		y=true;
    		ans+="++";
    	}
    	else
    	{
    		ans+=s2;
    	}
    	ans+="\n";
    }
    
    if(y)
    {
    	cout << "YES\n" << ans;
    }
    else
    {
    	cout << "NO";
    }
}