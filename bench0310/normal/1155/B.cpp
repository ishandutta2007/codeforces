#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int moves=(n-11)/2;
	vector<int> v;
	for(int i=0;i<n;i++)
    {
        if(s[i]=='8') v.push_back(i);
    }
    if((int)v.size()<=moves) cout << "NO" << endl;
    else
    {
        int pos=v[moves];
        int req=pos-moves;
        if(req<=moves) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}