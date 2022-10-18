#include <bits/stdc++.h>

#define fin freopen("gold.in", "r", stdin)
#define fout freopen("gold.out", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) (x)*(x)
#define elif else if
#define maxint 2147483647
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

int n;

int main()
{
    fast;
    scanf(I,&n);
    if (n==1) printf("0 1");
    elif (n==2) printf("0 2");
    else printf(I" "I,(n/7)*2+(n%7==6),2+((n-2)/7)*2+((n-2)%7==6));
    return 0;
}