#include <bits/stdc++.h>
using namespace std;
int chuyen(char c)
{
    return (int) c-48;
}
int main()
{
    int check=0;
    int n,x[105];
    cin >> n;
    char a[105];
    cin >> a;
    int tong;
    int den[105];
    den[0]=0;
    for (int i=1;i<=n;i++)
    {
        x[i]=chuyen(a[i-1]);
        tong+=x[i];
        den[i]=den[i-1]+x[i];
    }
    //gnkdvkasnvaks
    for (int i=1;i<=n-1;i++)
    {
        int tong1=0;
        for (int j=i+1;j<=n;j++)
        {
            tong1+=x[j];
            if (tong1==den[i] && den[j]==den[n])
            {
                check=1;
            }
            if (tong1==den[i]) tong1=0;
            if (tong1>den[i]) break;
        }
    }
    if (check==0) cout << "NO";
    else cout << "YES";
}