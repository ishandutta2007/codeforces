#include <bits/stdc++.h>

using namespace std;

int n;
string s,a,b;

void solve(int l,int r)
{
    if(l==r)
    {
        a+=s[l];
        return;
    }
    if(s[l]==s[r])
    {
        a+=s[l];
        b+=s[r];
        solve(l+1,r-1);
        return;
    }
    if(r-l+1<=3)
    {
        a+=s[l];
        return;
    }
    if(s[l]==s[r-1])
    {
        a+=s[l];
        b+=s[r-1];
        solve(l+1,r-2);
    }
    else if(s[l+1]==s[r])
    {
        a+=s[l+1];
        b+=s[r];
        solve(l+2,r-1);
    }
    else
    {
        a+=s[l+1];
        b+=s[r-1];
        solve(l+2,r-2);
    }
}

int main()
{
	cin >> s;
	int n=s.size();
	solve(0,n-1);
	string res=a;
    reverse(b.begin(),b.end());
    res+=b;
    cout << res << endl;
	return 0;
}