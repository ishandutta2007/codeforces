#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	char f[10];
	for(int i=1;i<10;i++) cin >> f[i];
	for(int o=0;o<n;o++)
    {
        if(f[s[o]-'0']>s[o])
        {
            for(int i=o;i<n;i++)
            {
                if(f[s[i]-'0']>=s[i]) s[i]=f[s[i]-'0'];
                else break;
            }
            break;
        }
    }
    cout << s << endl;
	return 0;
}