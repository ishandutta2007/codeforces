#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    char str[n+1];
    cin >> str;
    char res[m+1];
    cin >> res;
    //cout << str << " " << res;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='*')
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        if(!strcmp(str,res))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }
    if(m<(n-1))
    {
        cout << "NO" << endl;
        return 0;
    }
    if(strncmp(str,res,idx))
    {
        cout << "NO" << endl;
        return 0;
    }
    int cnt=m-1;
    for(int i=n-1;i>idx;i--)
    {
        if(str[i]!=res[cnt])
        {
            cout << "NO";
            return 0;
        }
        cnt--;
    }
    for(int i=idx;i<=cnt;i++)
    {
        if(!islower(res[i]))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}