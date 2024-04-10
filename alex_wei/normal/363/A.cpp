#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s; 
int main()
{
	cin>>s;
	for(int i=s.size()-1;~i;i--){
		int num=s[i]-'0';
		if(num>=5)cout<<"-O|",num-=5;
		else cout<<"O-|";
		for(int i=num;i;i--)
			cout<<'O';
		cout<<'-';
		for(int i=4-num;i;i--)
			cout<<'O';
		cout<<endl;
	}
	return 0;
}