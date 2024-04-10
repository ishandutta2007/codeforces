#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool found=0;
	int a,b;
	for(int i=0;i<n-1;i++)
    {
        if(s[i]>s[i+1])
        {
            found=1;
            a=i+1;
            b=i+2;
            break;
        }
    }
    if(found) cout << "YES\n" << a << " " << b << endl;
    else cout << "NO" << endl;
	return 0;
}