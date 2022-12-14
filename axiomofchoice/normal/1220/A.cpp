#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
for(int i=(a),i##end=(b);i<i##end;i++)
int n;
string s;
int zero,one;
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	if(s[i]=='z')zero++;
	else if(s[i]=='n')one++;
	repeat(i,0,one)
		cout<<"1 ";
	repeat(i,0,zero)
		cout<<"0 ";
	cout<<endl;
	return 0;
}