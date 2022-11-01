#include <bits/stdc++.h>

using namespace std;

int ab(int a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        sort(s.begin(),s.end());
        vector<int> v(26,0);
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        vector<int> even,odd;
        for(int o=0;o<26;o++)
        {
            for(int i=0;i<v[o];i++)
            {
                if(o&1) odd.push_back(o);
                else even.push_back(o);
            }
        }
        if(min(even.size(),odd.size())==0)
        {
            cout << s << endl;
            continue;
        }
        bool found=0;
        int a,b;
        for(int o=0;o<26;o+=2)
        {
            for(int i=1;i<26;i+=2)
            {
                if(min(v[o],v[i])==0) continue;
                if(ab(o-i)!=1)
                {
                    found=1;
                    a=o;
                    b=i;
                    break;
                }
            }
            if(found) break;
        }
        if(!found)
        {
            cout << "No answer" << endl;
            continue;
        }
        string res;
        for(int i=0;i<(int)even.size();i++)
        {
            if(even[i]!=a) res+=(char)(even[i]+'a');
        }
        for(int i=0;i<v[a];i++) res+=(char)(a+'a');
        for(int i=0;i<v[b];i++) res+=(char)(b+'a');
        for(int i=0;i<(int)odd.size();i++)
        {
            if(odd[i]!=b) res+=(char)(odd[i]+'a');
        }
        cout << res << endl;
    }
	return 0;
}