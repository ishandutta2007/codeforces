#include <bits/stdc++.h>

using namespace std;

string gen(string s,int k)
{
    int n=s.size();
    string t;
    for(int i=k-1;i<n;i++) t+=s[i];
    if((n-k+1)&1) for(int i=k-2;i>=0;i--) t+=s[i];
    else for(int i=0;i<k-1;i++) t+=s[i];
    return t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string res=s;
        int k=1;
        for(int i=2;i<=n;i++)
        {
            string x=gen(s,i);
            if(x<res)
            {
                res=x;
                k=i;
            }
        }
        cout << res << "\n";
        cout << k << "\n";
    }
    return 0;
}