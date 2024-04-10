#include <bits/stdc++.h>

using namespace std;

long long n;
string s;

long long bad(int l,int r)
{
    bool ok=0;
    for(int o=l;o<=r;o++)
    {
        for(int i=1;i<=9;i++)
        {
            if(o+2*i>r) break;
            if(s[o]==s[o+i]&&s[o+i]==s[o+2*i]) ok=1;
        }
    }
    return (1-ok);
}

int main()
{
	cin >> s;
	n=s.size();
	long long res=(n*(n-1)/2);
	for(int o=0;o<n;o++) for(int i=o+1;i<min(o+8,(int)n);i++) res-=bad(o,i);
	cout << res << endl;
	return 0;
}