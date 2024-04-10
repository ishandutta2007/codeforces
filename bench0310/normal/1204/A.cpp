#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if(s=="0")
    {
        cout << 0 << endl;
        return 0;
    }
	if((s.size()&1)) s='0'+s;
	vector<int> v;
	for(int i=0;i<(int)s.size();i+=2) v.push_back(2*(s[i]-'0')+(s[i+1]-'0'));
	int res=v.size();
	bool b=0;
	for(int i=1;i<(int)v.size();i++) if(v[i]>0) b=1;
	if(v[0]==1&&b==0) res--;
	cout << res << endl;
	return 0;
}