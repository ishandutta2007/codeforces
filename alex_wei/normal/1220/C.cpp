#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int al[26];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		al[s[i]-'a']++;
		int pd=0;
		for(int j=0;j<s[i]-'a';j++)
			if(al[j])
				pd=1;
		if(pd)cout<<"Ann\n";
		else cout<<"Mike\n";
	}
    return 0;
}