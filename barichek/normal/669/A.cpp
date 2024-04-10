#include <bits/stdc++.h>

#define fin freopen("file.in", "r", stdin)
#define fout freopen("file.out", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define timer int timer=clock()
#define sqr(x) (x)*(x)
#define maxint 2147483647
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define D "%lf"
#define mp make_pair
#define pb push_back
#define sec second
#define fir first

using namespace std;

typedef pair <int,int> pii;
typedef vector <pii> vii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;

int main()
{
    fast;
    int n;
    scanf(I,&n);
    int ans=(n/3)*2;
    if (n%3) ans++;
    printf(I,ans);
    return 0;
}