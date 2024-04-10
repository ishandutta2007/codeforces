#include <bits/stdc++.h>

using namespace std;

int solve(string s,string t)
{
    int cnt=0;
    for(int o=0;o<(int)t.size();o++)
    {
        int idx=s.find(t[o],o);
        for(int i=idx-1;i>=o;i--)
        {
            swap(s[i],s[i+1]);
            cnt++;
        }
    }
    return cnt;
}

bool db(string s)
{
    vector<bool> v(26,0);
    for(char c:s)
    {
        if(v[c-'a']) return 1;
        v[c-'a']=1;
    }
    return 0;
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        string a=s;
        string b=t;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b) cout << "NO" << endl;
        else if(db(a)) cout << "YES" << endl;
        else if((solve(s,a)-solve(t,b))&1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}