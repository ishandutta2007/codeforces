#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1500
#define MOD ((ll)1e16+7)

string s;
char c;
bool mark[26];
ll k,ans;
map <ll,bool> mp;

int main()
{ 
    cin>>s;
    for(int i=0;i<26;i++)
    	cin>>c,mark[i]=((c=='1')?1:0);
    cin>>k;
		
    for(int i=0;i<s.size();i++)
    {
    	ll hash=0,k2=0;
 		for(int j=i;j<s.size();j++)
		{
			if(!mark[s[j]-'a'])k2++;
			if(k2>k)
				break;
			hash=hash*37+(s[j]-'a'+1),hash%=MOD;
			//cerr<<i<<" "<<j<<" "<<hash<<"\n";
			if(!mp[hash])
				ans++,mp[hash]=1;		
		}   	
    }
    cout<<ans;
    return 0;
}