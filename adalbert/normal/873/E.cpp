#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;

pair<int,int> a[5000];
int an[5000],b[5000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fir;
        a[i].sec=i;
    }

    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        b[i]=a[i].fir-a[i+1].fir;

    int ans=-1e9;
    int c1,c2,c3;
    int ac1=-1e9;
    int ac2=-1e9;
    int ac3=-1e9;
    for (int cnt1=1;cnt1<=n;cnt1++)
        for (int cnt2=(cnt1+1)/2;cnt2<=min(cnt1*2,n-cnt1);cnt2++)
        {

            int left=cnt1+cnt2+max(1,max(cnt1+1,cnt2+1)/2);
            int right=cnt1+cnt2+min(n-cnt1-cnt2,min(cnt1,cnt2)*2);
            int mx=-1e9;
            int imx=0;
            for (int i=left;i<=right;i++)
                if (b[i]>mx)
                {
                    mx=b[i];
                    imx=i;
                }
            if (mx!=-1e9)
            if (ac1<b[cnt1] || (ac1==b[cnt1] && ac2<b[cnt1+cnt2]) || (ac1==b[cnt1] && ac2==b[cnt1+cnt2] && ac3<mx))
            {
                c1=cnt1;
                c2=cnt2;
                c3=imx-cnt1-cnt2;
                ac1=b[cnt1];
                ac2=b[cnt1+cnt2];
                ac3=mx;
            }
        }


    for (int i=1;i<=n;i++)
        if (i<=c1)
        an[a[i].sec]=1; else
        if (i<=c1+c2)
        an[a[i].sec]=2; else
        if (i<=c1+c2+c3)
        an[a[i].sec]=3; else
        an[a[i].sec]=-1;

    for (int i=1;i<=n;i++)
        cout<<an[i]<<' ';
}
/*
3
5 1 4 9 2 6
0
3 1 6
0 3 6
3 2 6
0 1 6
2 3 3
1 2 3
0 3 4

*/