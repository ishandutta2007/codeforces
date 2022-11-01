#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<bool> v(10,0);
	for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            for(int j=0;j<10;j++)
            {
                if(v[j]==0)
                {
                    v[j]=1;
                    break;
                }
            }
        }
        else if(s[i]=='R')
        {
            for(int j=9;j>=0;j--)
            {
                if(v[j]==0)
                {
                    v[j]=1;
                    break;
                }
            }
        }
        else v[s[i]-'0']=0;
    }
    for(int i=0;i<10;i++) cout << v[i];
    cout << endl;
	return 0;
}