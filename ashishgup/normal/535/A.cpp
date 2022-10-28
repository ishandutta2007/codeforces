#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

vector<string> ones={" ", "one ", "two ", "three ", "four ", 
				"five ", "six ", "seven ", "eight ", 
				"nine ", "ten ", "eleven ", "twelve ", 
				"thirteen ", "fourteen ", "fifteen ", 
				"sixteen ", "seventeen ", "eighteen ", 
				"nineteen "}; 

vector<string> ten={ "", "", "twenty ", "thirty ", "forty ", 
				"fifty ", "sixty ", "seventy ", "eighty ", 
				"ninety "}; 
  
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<"zero";
		return 0;
	}
	string ans="";
	if(n>19)
		ans+=ten[n/10] + ones[n%10];
	else
		ans+=ones[n];
	while(ans.back()==' ')
		ans.pop_back();
	for(auto &it:ans)
		if(it==' ')
			it='-';
	cout<<ans;
	return 0;
}