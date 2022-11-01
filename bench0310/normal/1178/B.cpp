#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	vector<long long> one(n,0);
	vector<long long> two(n,0);
	for(int i=1;i<n;i++) one[i]=one[i-1]+(s[i]==s[i-1]&&s[i]=='v');
    for(int i=n-2;i>=0;i--) two[i]=two[i+1]+(s[i]==s[i+1]&&s[i]=='v');
    long long res=0;
    for(int i=1;i<n-1;i++) if(s[i]=='o') res+=(one[i-1]*two[i+1]);
    cout << res << endl;
	return 0;
}