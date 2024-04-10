#include<bits/stdc++.h>
using namespace std;
string s[5]={"Danil","Olya","Slava","Ann","Nikita"},k;
int ans;
int main()
{
	cin>>k;
	for(int i=0;i<5;i++){
		int j=k.find(s[i]);
		while(j!=-1)j++,ans++,j=k.find(s[i],j);
	}
	cout<<(ans==1?"YES":"NO");
	return 0;
}