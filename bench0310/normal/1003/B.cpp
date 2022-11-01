#include <bits/stdc++.h>

using namespace std;

string solve(int a,int b,int x)
{
    string s;
    for(int i=0;i<x-1;i++)
    {
        if(!(i&1))
        {
            s+='0';
            a--;
        }
        else
        {
            s+='1';
            b--;
        }
    }
	if(s.back()=='0')
    {
        for(int i=0;i<b;i++) s+='1';
        for(int i=0;i<a;i++) s+='0';
    }
    else
    {
        for(int i=0;i<a;i++) s+='0';
        for(int i=0;i<b;i++) s+='1';
    }
    return s;
}

int main()
{
	int a,b,x;
	cin >> a >> b >> x;
    string s=solve(a,b,x);
    int cnt=0;
    for(int i=1;i<a+b;i++) if(s[i-1]!=s[i]) cnt++;
    if(cnt==x) cout << s << endl;
    else
    {
        s=solve(b,a,x);
        for(int i=0;i<a+b;i++) s[i]=(s[i]=='0'?'1':'0');
        cout << s << endl;
    }
	return 0;
}