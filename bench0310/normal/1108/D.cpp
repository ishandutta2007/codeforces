#include <bits/stdc++.h>

using namespace std;

char dif(char a)
{
    if(a=='B') return 'G';
    else return 'B';
}

char diff(char a,char b)
{
    if(a==b) return dif(a);
    if(a>b)
    {
        char temp=a;
        a=b;
        b=temp;
    }
    if(a=='B'&&b=='G') return 'R';
    if(a=='B'&&b=='R') return 'G';
    return 'B';
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(-1);
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1]) v.push_back(i);
    }
    v.push_back(n-1);
    int cnt=0;
    for(int o=1;o<(int)v.size();o++)
    {
        if(v[o]-v[o-1]>=2)
        {
            if(((v[o]-v[o-1])%2)==0)
            {
                for(int i=v[o-1]+1;i<=v[o];i+=2)
                {
                    if(i==0) s[i]=dif(s[i+1]);
                    else s[i]=diff(s[i-1],s[i+1]);
                    cnt++;
                }
            }
            else
            {
                for(int i=v[o-1]+2;i<=v[o];i+=2)
                {
                    s[i]=diff(s[i-1],s[i+1]);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    cout << s << endl;
    return 0;
}