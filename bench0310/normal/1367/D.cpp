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
        string s;
        cin >> s;
        vector<int> v(26,0);
        for(char c:s) v[c-'a']++;
        int m;
        cin >> m;
        vector<int> b(m);
        for(int i=0;i<m;i++) cin >> b[i];
        string res(m,'$');
        int idx=25;
        int cnt=m;
        while(cnt)
        {
            vector<int> now;
            for(int i=0;i<m;i++)
            {
                if(b[i]==0)
                {
                    now.push_back(i);
                    b[i]=-1;
                    cnt--;
                }
            }
            for(int pos:now)
            {
                for(int i=0;i<m;i++) if(b[i]>0) b[i]-=abs(i-pos);
            }
            while(v[idx]<(int)now.size()) idx--;
            for(int pos:now) res[pos]=(idx+'a');
            idx--;
        }
        cout << res << "\n";
    }
    return 0;
}