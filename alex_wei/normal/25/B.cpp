#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cout<<s[i];
		if(i%2==1&&n-i>2)cout<<"-";
	}
    return 0;
}