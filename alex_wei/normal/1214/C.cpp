#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,l,r,num;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		s[i]=='('?l++:r++;
	if(l!=r)cout<<"No",exit(0);
	l=0,r=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(')l++;
		else r++;
		if(r==1){
			if(l>0)l--,r--;
			else if(!num)num++,r--;
			else cout<<"No",exit(0);
		}
	}
	cout<<"Yes";
    return 0;
}