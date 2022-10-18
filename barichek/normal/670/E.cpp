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

ll n,now,head,endi,mas[10000000],l;
string s,work;
struct point
{
    ll from,to,anal;
} a[1000000];

int main()
{
    fast;
    cin>>n>>now>>now;
    now--;
    cin>>s;
    cin>>work;
    for (int i=0;i<s.length();i++)
    {
        if (i!=0) a[i].from=i-1;
        if (i!=s.length()-1) a[i].to=i+1;
    }
    for (int i=0;i<s.length();i++)
        if (s[i]=='(') mas[++l]=i;
        else
            a[i].anal=mas[l], l--,
            a[a[i].anal].anal=i;
    head=0;
    endi=s.length()-1;
    for (int i=0;i<work.length();i++)
    {
        if (work[i]=='L') now=a[now].from;
        elif (work[i]=='R') now=a[now].to;
        else
        {
            int dop=now;
            if (a[now].anal<now) dop=a[now].anal;
            if (dop!=head&&a[dop].anal!=endi)
                a[a[dop].from].to=a[a[dop].anal].to,
                a[a[a[dop].anal].to].from=a[dop].from,
                now=a[a[dop].anal].to;
            else
                if (dop==head) head=a[a[dop].anal].to, now=a[a[dop].anal].to;
                else endi=a[dop].from, now=a[dop].from;
        }
        //cout<<head<<" "<<endi<<"\n";
        /*
        cout<<now<<"\n";
        int dop_=head;
        while (true)
        {
            cout<<s[dop_];
            if (dop_==endi) break;
            dop_=a[dop_].to;
        }
        cout<<"\n";
        */

    }
    now=head;
    while (true)
    {
        cout<<s[now];
        if (now==endi) break;
        now=a[now].to;
    }
    return 0;
}