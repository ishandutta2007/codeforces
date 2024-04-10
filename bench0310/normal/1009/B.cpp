#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	string res;
	for(int i=0;i<n;i++) if(s[i]!='1') res+=s[i];
	bool ok=0;
    for(int i=0;i<(int)res.size();i++)
    {
        if(res[i]=='2')
        {
            for(int j=0;j<i;j++) cout << res[j];
            for(int j=0;j<n-(int)res.size();j++) cout << '1';
            for(int j=i;j<(int)res.size();j++) cout << res[j];
            ok=1;
            break;
        }
    }
    if(ok==0)
    {
        cout << res;
        for(int j=0;j<n-(int)res.size();j++) cout << '1';
    }
    cout << endl;
	return 0;
}