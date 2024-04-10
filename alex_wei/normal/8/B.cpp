#include<bits/stdc++.h>
using namespace std;
string s;
int x=102,y=102,mp[204][204];
int main()
{
	cin>>s;
	mp[x][y]=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='L')y--;
		if(s[i]=='R')y++;
		if(s[i]=='U')x++;
		if(s[i]=='D')x--;
		if(mp[x][y])cout<<"BUG",exit(0);
		mp[x][y]=i+2;
		for(int a=-1;a<2;a++)
			for(int b=-1;b<2;b++)
				if(abs(a)+abs(b)==1&&mp[x+a][y+b]&&abs(mp[x+a][y+b]-mp[x][y])>1)
					cout<<"BUG",exit(0);
	}
	cout<<"OK";
    return 0;
}