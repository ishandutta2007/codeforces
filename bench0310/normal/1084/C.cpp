#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    const long long MOD=1000000007;
    string s;
    cin >> s;
    int n=s.size();
    long long l[n];
    int last=0;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            l[i]=sum+1;
            if(l[i]>=MOD) l[i]%=MOD;
        }
        else if(s[i]=='b')
        {
            l[i]=0;
            while(last<i)
            {
                sum+=l[last];
                if(sum>=MOD) sum%=MOD;
                last++;
            }
        }
        else l[i]=0;
    }
    while(last<n)
    {
        sum+=l[last];
        if(sum>=MOD) sum%=MOD;
        last++;
    }
    cout << sum << endl;
    return 0;
}