#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define files freopen("file.in", "r", stdin); freopen("file.out", "w", stdout);
#define maxint 2147483647

using namespace std;

int main()
{
    fast;
    string s;
    getline(cin,s);
    int i;
    char j;
    for (i=1;i<s.length();i++)
        if (s[i]==s[i-1])
            for (j='a';j<='z';j++)
                if (j!=s[i-1]&&j!=s[i+1])
                {
                    s[i]=j;
                    break;
                }
    cout<<s;
    return 0;
}