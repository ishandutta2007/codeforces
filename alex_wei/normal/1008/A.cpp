#include <bits/stdc++.h>
using namespace std;
string s;
char p[6]={'a','e','i','o','u','n'};
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		int g=1;
		for(int j=0;j<6;j++)
			if(s[i]==p[j])
				g=0;
		if(g){
			if(i==s.size()-1)
				cout<<"NO",exit(0);
			int d=1;
			for(int j=0;j<5;j++)
				if(s[i+1]==p[j])
					d=0;
			if(d)cout<<"NO",exit(0);
		}
	}
	cout<<"YES";
    return 0;
}