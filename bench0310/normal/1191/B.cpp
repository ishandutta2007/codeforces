#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char,int> m={{'m',0},{'p',1},{'s',2}};
	int a[3][9];
	memset(a,0,sizeof a);
	string s;
	for(int i=0;i<3;i++)
    {
        cin >> s;
        int one=m[s[1]];
        int two=(s[0]-'0'-1);
        a[one][two]++;
    }
    int res=2;
    for(int o=0;o<3;o++) for(int i=0;i<9;i++) res=min(res,3-a[o][i]);
    for(int o=0;o<3;o++)
    {
        for(int i=0;i<7;i++)
        {
            int cnt=0;
            for(int j=0;j<3;j++) cnt+=min(1,a[o][i+j]);
            res=min(res,3-cnt);
        }
    }
    cout << res << endl;
	return 0;
}