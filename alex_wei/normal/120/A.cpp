#include<bits/stdc++.h>
using namespace std;
int i;
string s;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>s>>i;
	if(s=="front")cout<<(i==1?"L":"R");
	else cout<<(i==1?"R":"L");
	return 0;
}