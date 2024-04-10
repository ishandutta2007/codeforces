#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

set<char> vowel;

string work(string s)
{
	int n=s.size();
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(vowel.find(s[i])!=vowel.end())
		{
			ans+=s[i];
			while(i<n && vowel.find(s[i])!=vowel.end())
				i++;
			i--;
		}
		else
		{
			ans+=s[i];
		}
	}
	return ans;
}

int32_t main()
{
    IOS;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    vowel.insert('y');
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans=work(s);
    cout<<ans;
    return 0;
}