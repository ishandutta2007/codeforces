#include <bits/stdc++.h>

using namespace std;

string sum(string s,int idx) //left: 0..idx
{
    string a,b;
    for(int i=0;i<=idx;i++) a+=s[i];
    for(int i=idx+1;i<(int)s.size();i++) b+=s[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int temp=0;
    string res;
    for(int i=0;i<(int)max(a.size(),b.size());i++)
    {
        int now=temp;
        if(i<(int)a.size()) now+=(a[i]-'0');
        if(i<(int)b.size()) now+=(b[i]-'0');
        res+=((now%10)+'0');
        temp=now/10;
    }
    if(temp!=0) res+=(temp-'0');
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	vector<string> v;
	for(int i=l/2;i<min(l/2+3,l);i++)
    {
        if(s[i]!='0') v.push_back(sum(s,i-1));
    }
    for(int i=l/2-1;i>max(0,l/2-3);i--)
    {
        if(s[i]!='0') v.push_back(sum(s,i-1));
    }
	for(int i=l/2+1;i<l;i++)
    {
        if(s[i]!='0')
        {
            v.push_back(sum(s,i-1));
            break;
        }
    }
    for(int i=l/2-1;i>0;i--)
    {
        if(s[i]!='0')
        {
            v.push_back(sum(s,i-1));
            break;
        }
    }
    string res;
    int best=1000000000;
    for(int i=0;i<(int)v.size();i++)
    {
        if((int)v[i].size()<best)
        {
            best=v[i].size();
            res=v[i];
        }
        else if((int)v[i].size()==best) res=min(res,v[i]);
    }
    cout << res << endl;
	return 0;
}