#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=3e5;

int ans=0;
int a[arr];

signed main()
{
    int n;
    cin>>n;
    int sum=0;
    multiset<int> setik;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        setik.insert(a[i]);
    }

    int ans=0;
    while (setik.size()!=1)
    {

        if (setik.size()%2==0)
        {
            int fir=*setik.begin();
            setik.erase(setik.find(fir));
            int sec=*setik.begin();
            setik.erase(setik.find(sec));

            setik.insert(fir+sec);
            ans+=fir+sec;
        } else
        {
            int fir=*setik.begin();
            setik.erase(setik.find(fir));
            int sec=*setik.begin();
            setik.erase(setik.find(sec));
            int th=*setik.begin();
            setik.erase(setik.find(th));
            setik.insert(fir+sec+th);
            ans+=fir+sec+th;
        }

    }


    if (setik.size()!=1)
    {
        for (auto i:setik)
            ans+=i;
    }
    cout<<ans;
}

/*
!!! https://pastebin.com/jHpxMZq3
*/