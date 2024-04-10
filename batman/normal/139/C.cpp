#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,k,mod[4];
bool check(char c){return c=='a' || c=='e' || c=='o' || c=='u' || c=='i';}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		string s[4],t[4];
		for(int j=0;j<4;j++)
		{
			cin>>s[j];
			ll num=0;
			for(int q=(ll)s[j].size()-1;q>=0;q--)
			{
				if(check(s[j][q]))num++;
				if(num==k){for(int p=q;p<(ll)s[j].size();p++)t[j]+=s[j][p];break;}
			}
			if(num<k)return cout<<"NO",0;
		}
		if(t[0]==t[1])
		{
			if(t[1]==t[2] && t[2]==t[3])mod[0]++;
			else if(t[2]==t[3])mod[1]++;
			else return cout<<"NO",0;
		}
		else if(t[0]==t[2])
		{
			if(t[1]==t[3])mod[2]++;
			else return cout<<"NO",0;
		}
		else if(t[0]==t[3])
		{
			if(t[1]==t[2])mod[3]++;
			else return cout<<"NO",0;
		}
		else return cout<<"NO",0;
	}
	if((mod[1] && mod[2]) || (mod[1] && mod[3]) || (mod[2] && mod[3]))return cout<<"NO",0;
	if(mod[1])cout<<"aabb";
	else if(mod[2])cout<<"abab";
	else if(mod[3])cout<<"abba";
	else cout<<"aaaa";
	return 0;
}