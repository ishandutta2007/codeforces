#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int res=0;
	for(int i=n-x;i<n;i++)
    {
        if(i==n-y-1&&s[i]=='0') res++;
        if(i!=n-y-1&&s[i]=='1') res++;
    }
    cout << res << endl;
	return 0;
}