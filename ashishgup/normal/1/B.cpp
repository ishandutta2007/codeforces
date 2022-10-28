#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int check(string s)
{
    stringstream ss(s);
    char ch1, ch2;
    int d1, d2;
    ss>>ch1>>d1>>ch2>>d2;
    if(d1>0 &&  d2>0 && ch1=='R' && ch2=='C')
        return 1;
    return 0;
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(check(s))
        {
            stringstream ss(s);
            char ch;
            ss>>ch;
            int r, c;
            ss>>r>>ch>>c;
            string ans="";
            while(c)
            {
                int cur=c%26;
                if(!cur)
                    cur=26;
                ans=(char)(cur-1+'A') + ans;
                c-=cur;
                c/=26;
            }
            cout<<ans<<r<<endl;
        }
        else
        {
            int sz=s.size();
            string cur="", row="";
            int i, len;
            for(i=0;i<sz;i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                    break;
                cur+=s[i];
            }
            len=i;
            for(;i<sz;i++)
            {
                row+=s[i];
            }
            int mult=1;
            int col=0;
            for(i=len-1;i>=0;i--)
            {
                col+=mult*(cur[i]-'A'+1);
                mult*=26;
            }
            cout<<"R"<<row<<"C"<<col<<endl;
        }
    }
    return 0;
}