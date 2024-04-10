#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define     Time            printf("\nTime : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC);
#define     fori(i,j,k)     for(int (i)=(j);(i)<(k);(i)++)
#define     rep(i,k)        fori(i,0,k)
#define     all(x)          ((x).begin(),(x).end())
#define     testin          freopen("a.in.txt","r+",stdin)
#define     testout         freopen("a.out.txt","w+",stdout)
#define     pb              push_back()
#define     ppb             pop_back()

int main()
{
    //testin;testout;

    int n;
    cin>> n;

    int cnt=0;
    int t=0;
    int t1=0;

    rep(i,n)
    {
        int a;
        cin >> a;
        if(a%2==1)
        {
            cnt++;
            t=i;
        }
        else
        {
            t1=i;
        }
    }

    if(cnt==1)
    {
        cout << t+1;
    }
    else
    {
        cout << t1+1;
    }
}