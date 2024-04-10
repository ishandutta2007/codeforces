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

bool use[100000];
int n,a[100000];
string s;

int main()
{
    //fast;
    scanf(I,&n);
    cin >> s;
    
   
    
    for (int i=0;i<n;i++)
        scanf(I,&a[i]);
    int i=0;
    while (i<n&&i>=0)
    {
        if (use[i]) { cout<<"INFINITE"<<endl; return 0;}
        use[i]=true;
        if (s[i]=='>') i+=a[i];
        else i-=a[i];
    }
    cout<<"FINITE"<<endl;
    return 0;
}