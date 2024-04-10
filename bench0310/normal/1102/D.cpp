#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c[3];
    int m=n/3;
    for(int i=0;i<3;i++) c[i]=0;
    for(int i=0;i<n;i++) c[s[i]-'0']++;
    bool b[n];
    for(int i=0;i<n;i++) b[i]=0;
    for(int i=0;c[0]<m;i++)
    {
        int id=s[i]-'0';
        if(c[id]>m)
        {
            s[i]='0';
            c[id]--;
            c[0]++;
            b[i]=1;
        }
    }
    for(int i=n-1;c[2]<m;i--)
    {
        int id=s[i]-'0';
        if(c[id]>m)
        {
            s[i]='2';
            c[id]--;
            c[2]++;
            b[i]=1;
        }
    }
    for(int i=0;c[1]<m&&i<n;i++)
    {
        int id=s[i]-'0';
        if(s[i]=='2'&&b[i]==0&&c[id]>m)
        {
            s[i]='1';
            c[1]++;
            c[2]--;
            b[i]=1;
        }
    }
    for(int i=n-1;c[1]<m&&i>=0;i--)
    {
        int id=s[i]-'0';
        if(s[i]=='0'&&b[i]==0&&c[id]>m)
        {
            s[i]='1';
            c[1]++;
            c[0]--;
            b[i]=1;
        }
    }
    cout << s << endl;
    return 0;
}