#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	int n,m;
	string s;
	cin >> n >> s >> m;
	vector<vector<int>> v(n,vector<int>(26,0));
	for(int i=0;i<n;i++)
    {
        if(i>>0) v[i]=v[i-1];
        v[i][(s[i]-'a')]++;
    }
	for(int o=0;o<m;o++)
    {
        string t;
        cin >> t;
        vector<int> a(26,0);
        for(int i=0;i<(int)t.size();i++) a[(t[i]-'a')]++;
        int l=-1,r=n-1;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            bool ok=1;
            for(int i=0;i<26;i++)
            {
                if(v[mid][i]<a[i]) ok=0;
            }
            if(ok) r=mid;
            else l=mid;
        }
        cout << r+1 << endl;
    }
	return 0;
}