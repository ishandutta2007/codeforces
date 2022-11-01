#include<stdio.h>
#include<queue>
#include<time.h>
#include<iostream>
#include<string.h>
#include<list>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<ctime>
#include<map>
#include<stack>
#include<iomanip>
#include<string.h>
#include<string>
#define pr printf
#define sc scanf
#define str strlen
#define rev reverse
#define ll long long int
#define ss second
#define ff first
#define in freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define inn freopen("qsort.in","r",stdin);
#define outt freopen("qsort.out","w",stdout);
using namespace std;
    const int MX = 1000001;
    const int MI = 100001;
    const int MT = 10001;
   void solve()
   {
        string a, b, c;
        bool st = false;
        int l, kol = 0, i, kol2 = 0;
        cin >> a >> b >> c;
        a = a + b;
        sort(a.begin(),a.end());
        sort(c.begin(),c.end());
        if(a==c)
        cout<<"YES" << endl;
        else cout <<"NO" << endl;
   }
main()
{
        //in out
        solve();
    return 0;
}