#include <bits/stdc++.h>

using namespace std;

int n;

bool in(int r,int c)
{
    if(r<0||c<0||r>=n||c>=n) return 0;
    else return 1;
}

int main()
{
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++) cin >> s[i];
	int w[4][2]={{1,-1},{1,0},{1,1},{2,0}};
	bool ok=1;
	for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            if(s[o][i]=='.')
            {
                s[o][i]='#';
                for(int j=0;j<4;j++)
                {
                    if(!in(o+w[j][0],i+w[j][1])) ok=0;
                    else if(s[o+w[j][0]][i+w[j][1]]=='#') ok=0;
                    else s[o+w[j][0]][i+w[j][1]]='#';
                }
            }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}