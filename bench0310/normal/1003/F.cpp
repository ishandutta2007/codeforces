#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int p=307;
    const int mod=1000000007;
    int n;
    cin >> n;
    string s[n];
    int a[n];
    int idx=1;
    map<string,int> m;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        if(m.find(s[i])==m.end()) m.insert(make_pair(s[i],idx++));
        a[i]=m[s[i]];
    }
    int sum[n][n];
    for(int o=0;o<n;o++)
    {
        int cnt=s[o].size();
        sum[o][o]=cnt;
        for(int i=o+1;i<n;i++)
        {
            cnt+=(s[i].size()+1);
            sum[o][i]=cnt;
        }
    }
    int hashed[n][n];
    for(int o=0;o<n;o++)
    {
        int now=a[o];
        hashed[o][o]=now;
        for(int i=o+1;i<n;i++)
        {
            now=(p*now+a[i])%mod;
            hashed[o][i]=now;
        }
    }
    int res=sum[0][n-1];
    for(int o=1;o<=n;o++) //hash length
    {
        for(int i=0;i+o-1<n;i++) //main hash
        {
            int now=hashed[i][i+o-1];
            int cnt=1;
            for(int j=i+o;j+o-1<n;j++)
            {
                if(hashed[j][j+o-1]==now)
                {
                    cnt++;
                    j=j+o-1;
                }
            }
            if(cnt==1) continue;
            //int prev=res;
            res=min(res,sum[0][n-1]-cnt*sum[i][i+o-1]+cnt*o);
            /*if(prev!=res)
            {
                cout << "new best with: " << endl;
                for(int j=i;j<=i+o-1;j++) cout << s[j] << " ";
                cout << endl;
            }*/
        }
    }
    cout << res << endl;
	return 0;
}