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
    string s;
    cin >> s;

    int up=0,low=0;

    rep(i,s.size())
    {
        if(isupper(s[i]))
        {
            up++;
        }
        else
        {
            low++;
        }
    }

    if(low<up)
    {
        rep(i,s.size())
        {
            s[i]=toupper(s[i]);
        }
    }
    else
    {
        rep(i,s.size())
        {
            s[i]=tolower(s[i]);
        }
    }

    cout << s;
}