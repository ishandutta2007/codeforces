#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

#define     Time            printf("\nTime : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC);
#define     fori(i,j,k)     for(int (i)=(j);(i)<(k);(i)++)
#define     rep(i,k)        fori(i,0,k)
#define     all(x)          (x).begin(),(x).end()
#define     testin          freopen("a.in.txt","r",stdin)
#define     testout         freopen("a.out.txt","w",stdout)
#define     pb              push_back
#define     ppb             pop_back
#define     pf              push_front
#define     ppf             pop_front

int main()
{
    ios::sync_with_stdio(false);
    string s,s2,s3;
    cin >> s >> s2 >> s3;
    s+=s2;

    sort(all(s));
    sort(all(s3));

    s==s3?cout << "YES": cout << "NO";
}