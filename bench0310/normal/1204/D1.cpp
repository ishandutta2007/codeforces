#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	s='?'+s+'?';
	int l[n+1][2];
	int r[n+2][2];
	l[0][0]=l[0][1]=0;
	r[n+1][0]=r[n+1][1]=0;
	for(int i=n;i>=1;i--)
    {
        r[i][0]=max(r[i+1][0],r[i+1][1])+(s[i]=='0');
        r[i][1]=r[i+1][1]+(s[i]=='1');
    }
	for(int i=1;i<=n;i++)
    {
        l[i][0]=l[i-1][0]+(s[i]=='0');
        l[i][1]=max(l[i-1][0],l[i-1][1])+(s[i]=='1');
        if(s[i]=='1'&&max(l[i][0],l[i][1])==max(l[i][0]+1,l[i][1]-1)&&max(r[i][0],r[i][1])==max(r[i][0]+1,r[i][1]-1))
        {
            s[i]='0';
            l[i][0]++;
            l[i][1]--;
        }
    }
    for(int i=1;i<=n;i++) cout << s[i];
    cout << endl;
	return 0;
}