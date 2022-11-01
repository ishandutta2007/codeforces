#include <iostream>

using namespace std;

int main()
{
    const long long m=998244353;
    int n;
    string s;
    cin >> n >> s;
    long long cnt=3;
    long long l=1,r=1;
    for(int i=1;i<n-1;i++)
    {
        if(s[i]==s[0])
        {
            cnt++;
            l++;
        }
        else break;
    }
    for(int i=n-2;i>=1;i--)
    {
        if(s[i]==s[n-1])
        {
            cnt++;
            r++;
        }
        else break;
    }
    if(s[0]==s[n-1]) cnt=(cnt+(l*r)%m)%m;
    cout << cnt << endl;
    return 0;
}