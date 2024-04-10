#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],check[200005],id,n;
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    int cnt1=0;
    while (cnt1!=n)
    {
        cnt1++;
        int cnt=0;
        /*for (int i=1;i<=n;i++)
        {
            cout << check[b[i]] << " ";
        }
        cout << endl;*/
        if (check[b[cnt1]]==true)
        {
            cout << cnt << " ";
            continue;
        }
        for (int i=id+1;i<=n;i++)
        {
            check[a[i]]=true;
            cnt++;
            if (a[i]==b[cnt1])
            {
                id=i;
                cout << cnt << " ";
                break;
            }
        }
    }
}