#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
    cin >> q;
    while(q--)
    {
        string s,t,p;
        cin >> s >> t >> p;
        bool ok=1;
        int idx=0;
        for(int i=0;i<(int)t.size();i++)
        {
            if(idx==(int)s.size()) break;
            if(s[idx]==t[i]) idx++;
        }
        if(idx<(int)s.size()) ok=0;
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<(int)s.size();i++) a[s[i]-'a']++;
        for(int i=0;i<(int)p.size();i++) a[p[i]-'a']++;
        for(int i=0;i<(int)t.size();i++) b[t[i]-'a']++;
        for(int i=0;i<26;i++) if(a[i]<b[i]) ok=0;
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}