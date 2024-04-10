#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        string s;
        cin >> n >> k >> s;
        vector<int> v(26,0);
        for(char c:s) v[c-'a']++;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int x=(k%i);
            int c=1;
            while(x!=0)
            {
                x=(x+k)%i;
                c++;
            }
            int cnt=0;
            for(int j=0;j<26;j++) cnt+=(v[j]/c);
            if(cnt>=(i/c)) res=i;
        }
        cout << res << "\n";
    }
    return 0;
}