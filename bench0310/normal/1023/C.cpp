#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	string a,b;
	cin >> a;
	int cnt=0;
	for(int i=0;i<n;i++)
    {
        if(a[i]=='('&&cnt+1<=k-1)
        {
            b+='(';
            cnt++;
            k--;
        }
        if(a[i]==')'&&cnt>0)
        {
            b+=')';
            cnt--;
            k--;
        }
    }
    cout << b << endl;
	return 0;
}