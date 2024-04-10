#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string a="abacaba";
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string res;
        for(int i=0;i+6<n;i++)
        {
            bool ok=1;
            for(int j=0;j<7;j++) ok&=(s[i+j]=='?'||s[i+j]==a[j]);
            if(ok)
            {
                string b=s;
                for(int j=0;j<7;j++) b[i+j]=a[j];
                for(int j=0;j<n;j++) if(b[j]=='?') b[j]='d';
                int c=0;
                for(int j=0;j+6<n;j++) c+=(b.substr(j,7)==a);
                if(c==1) res=b;
            }
        }
        if(!res.empty()) cout << "Yes\n" << res << "\n";
        else cout << "No\n";
    }
    return 0;
}