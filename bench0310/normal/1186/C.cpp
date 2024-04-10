#include <bits/stdc++.h>

using namespace std;

void mod(int &a)
{
    a=(a%2);
}

int main()
{
	string a,b;
	cin >> a >> b;
	int n=a.size(),m=b.size();
	int inv=0;
	for(int i=0;i<m-1;i++) if(b[i]!=b[i+1]) inv++;
	int res=0;
	int cnt=0;
	for(int i=0;i<m;i++) if(b[i]!=a[i]) cnt++;
	mod(cnt);
	if(cnt==0) res++;
	for(int i=m;i<n;i++)
    {
        if(a[i-m]!=b[0]) cnt++;
        cnt+=inv;
        if(a[i]!=b[m-1]) cnt++;
        mod(cnt);
        if(cnt==0) res++;
    }
    cout << res << endl;
	return 0;
}