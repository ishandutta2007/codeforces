#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	string res;
    int now=1;
    res+=s[0];
    for(int i=0;i<n;i++)
    {
        if(!((now&1)&&res[now-1]==s[i]))
        {
            res+=s[i];
            now++;
        }
    }
    if(now&1)
    {
        res.pop_back();
        now--;
    }
    cout << n-now << endl;
    cout << res << endl;
	return 0;
}